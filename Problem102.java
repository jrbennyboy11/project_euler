import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 * Created by bbarnett on 1/13/2017.
 */
public class Problem102 {
    public static void main(String[] args) throws FileNotFoundException, IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("C://Users/bbarnett/Desktop/project_euler/src/p102_triangles.txt"));
        String line;
        int[][] triangles = new int[1000][6];
        int i;
        int j;
        int ttco = 0; //Total Triangles Containing Origin

        //Load text file of triangles into a double array
        for(i=0;i<1000;i++)
        {
            line = br.readLine();
            String[] points = line.split(",");

            for(j=0;j<6;j++)
                triangles[i][j] = Integer.parseInt(points[j]);
        }

        br.close();
        //Finish loading text file

        for(i=0;i<1000;i++)
        {
            for(j=0;j<6;j++)
                System.out.print(triangles[i][j] + " ");
            System.out.println();
        }

        for(i=0;i<1000;i++) {
            Point p1 = new Point(triangles[i][0], triangles[i][1]);
            Point p2 = new Point(triangles[i][2], triangles[i][3]);
            Point p3 = new Point(triangles[i][4], triangles[i][5]);
            Triangle t = new Triangle(p1,p2,p3);

            if(t.containsOrigin2())
                ttco++;
        }

        System.out.println("Total Triangles Containing Origin: " + ttco);
    }

    private static class Point{
        public int x;
        public int y;

        public Point(int x_coord, int y_coord)
        {
            x = x_coord;
            y = y_coord;
        }
    }

    private static class Triangle
    {
        Point p1;
        Point p2;
        Point p3;

        public Triangle (Point point1, Point point2, Point point3)
        {
            p1 = point1;
            p2 = point2;
            p3 = point3;
        }

        float getArea()
        {
            return (float)Math.abs((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y)+ p3.x*(p1.y-p2.y))/2.0);
        }


        public boolean containsOrigin()
        {
            Point p = new Point(0,0);

            float alpha = ((p2.y - p3.y)*(p.x - p3.x) + (p3.x - p2.x)*(p.y - p3.y)) /
                    ((p2.y - p3.y)*(p1.x - p3.x) + (p3.x - p2.x)*(p1.y - p3.y));
            float beta = ((p3.y - p1.y)*(p.x - p3.x) + (p1.x - p3.x)*(p.y - p3.y)) /
                    ((p2.y - p3.y)*(p1.x - p3.x) + (p3.x - p2.x)*(p1.y - p3.y));
            float gamma = 1.0f - alpha - beta;

            return alpha>0 && beta>0 && gamma>0;
        }

        public boolean containsOrigin2()
        {
            Point origin = new Point(0,0);

            Triangle t1 = new Triangle(p1,origin,p2);
            Triangle t2 = new Triangle(p2,origin,p3);
            Triangle t3 = new Triangle(p3,origin,p1);

            return this.getArea() == t1.getArea() + t2.getArea() + t3.getArea();
        }
    }
}

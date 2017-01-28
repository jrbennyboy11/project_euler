/**
 * Created by bbarnett on 1/27/2017.
 */
public class Problem345 extends Thread{
    
	public int row;
	public static final int row_length = 15;
	public static int[][] matrix = {
                {7,53,183,439,863,497,383,563,79,973,287,63,343,169,583},
                {627,343,773,959,943,767,473,103,699,303,957,703,583,639,913},
                {447,283,463,29,23,487,463,993,119,883,327,493,423,159,743},
                {217,623,3,399,853,407,103,983,89,463,290,516,212,462,350},
                {960,376,682,962,300,780,486,502,912,800,250,346,172,812,350},
                {870,456,192,162,593,473,915,45,989,873,823,965,425,329,803},
                {973,965,905,919,133,673,665,235,509,613,673,815,165,992,326},
                {322,148,972,962,286,255,941,541,265,323,925,281,601,95,973},
                {445,721,11,525,473,65,511,164,138,672,18,428,154,448,848},
                {414,456,310,312,798,104,566,520,302,248,694,976,430,392,198},
                {184,829,373,181,631,101,969,613,840,740,778,458,284,760,390},
                {821,461,843,513,17,901,711,993,293,157,274,94,192,156,574},
                {34,124,4,878,450,476,712,914,838,669,875,299,823,329,699},
                {815,559,813,459,522,788,168,586,966,232,308,833,251,631,107},
                {813,883,451,509,615,77,281,613,459,205,380,274,302,35,805}
        };	

	public static void main(String[] args)
    {
        int r1;
		Problem345[] threads = new Problem345[row_length];

        for(r1=0;r1 < row_length;r1++) {
            threads[r1] = new Problem345(r1);
			threads[r1].start();
        }

		try{
			for(r1=0;r1 < row_length;r1++)
		        threads[r1].join();
		}
		catch(InterruptedException ie){
			System.out.println("Thread Interrupted\n" + ie);
		}
    }

	public Problem345(int r1)
	{
		row = r1;
	}

	@Override
    public void run()
	{
		int r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15;
		int max = 0;
        boolean[] spaces_used = new boolean[row_length];

		System.out.println("Thread " + row + " started.");
		
		for (r2 = 0; r2 < row_length; r2++)
            for (r3 = 0; r3 < row_length; r3++)
                for (r4 = 0; r4 < row_length; r4++)
                    for (r5 = 0; r5 < row_length; r5++)
                        for (r6 = 0; r6 < row_length; r6++)
                            for (r7 = 0; r7 < row_length; r7++)
                                for (r8 = 0; r8 < row_length; r8++)
                                    for (r9 = 0; r9 < row_length; r9++)
                                        for (r10 = 0; r10 < row_length; r10++)
                                            for (r11 = 0; r11 < row_length; r11++)
                                                for (r12 = 0; r12 < row_length; r12++)
                                                    for (r13 = 0; r13 < row_length; r13++)
                                                        for (r14 = 0; r14 < row_length; r14++)
                                                            for (r15 = 0; r15 < row_length; r15++)
															{
                                                                for (int i = 0; i < row_length; i++)
                                                                    spaces_used[i] = false;

                                                                spaces_used[row] = true;
                                                                spaces_used[r2] = true;
                                                                spaces_used[r3] = true;
                                                                spaces_used[r4] = true;
                                                                spaces_used[r5] = true;
                                                                spaces_used[r6] = true;
                                                                spaces_used[r7] = true;
                                                                spaces_used[r8] = true;
                                                                spaces_used[r9] = true;
                                                                spaces_used[r10] = true;
                                                                spaces_used[r11] = true;
                                                                spaces_used[r12] = true;
                                                                spaces_used[r13] = true;
                                                                spaces_used[r14] = true;
                                                                spaces_used[r15] = true;

                                                                boolean possible_max = true;

                                                                for (int i = 0; i < spaces_used.length && possible_max; i++)
                                                                    possible_max = possible_max && spaces_used[i];

                                                                if (possible_max)
																{
                                                                    int temp = 0;
                                                                    temp += matrix[0][row];
                                                                    temp += matrix[1][r2];
                                                                    temp += matrix[2][r3];
                                                                    temp += matrix[3][r4];
                                                                    temp += matrix[4][r5];
                                                                    temp += matrix[5][r6];
                                                                    temp += matrix[6][r7];
                                                                    temp += matrix[7][r8];
                                                                    temp += matrix[8][r9];
                                                                    temp += matrix[9][r10];
                                                                    temp += matrix[10][r11];
                                                                    temp += matrix[11][r12];
                                                                    temp += matrix[12][r13];
                                                                    temp += matrix[13][r14];
                                                                    temp += matrix[14][r15];

                                                                    if (temp > max)
                                                                        max = temp;
                                                                }
                                                            }

		System.out.println("Thread " + row + " max: " + max);
	}
}

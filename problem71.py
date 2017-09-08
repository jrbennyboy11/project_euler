# https://projecteuler.net/problem=71
# 9/7/17

import pandas as pd
import numpy as np
from math import gcd
import sys
from multiprocessing import Process

def p71(tnum, min_d, max_d):
    global solutions
    thread_num = tnum
    min_denom = min_d
    max_denom = max_d
    less_than = 3/7
    solution = [1,3,0.3333333333333333]
    
    #print("Thread %d starting. Checking denominators between %d and %d" % (thread_num, min_denom, max_denom))
    
    for i in reversed(range(min_denom,max_denom+1)):
        #print("Checking denominator: %d" % i)
        j = 1
        too_large = False
        while j < i and not too_large:
            fract = j/i
            if fract < less_than and fract > solution[2]:
                solution = [j,i,fract]
            elif fract > less_than:
                too_large = True
            j += 1

    com_dom = gcd(solution[0],solution[1])
    #solutions[thread_num] = [int(solution[0]/com_dom), int(solution[2]/com_dom)]
    print("Thread %d - Solution: %d/%d = %s" % (thread_num,  int(solution[0]/com_dom),int(solution[1]/com_dom),'{0:.16f}'.format(solution[2])))

if __name__ == '__main__':
    min_denom = 2 # Minimum denominator
    max_denom = 1000000 # Maximum denominator
    
    incr = 25000 # Number of denominators to increment by
    
    max_processes = 8 # Number of threads to use
    
    curr_max = max_denom
    curr_min = max_denom - incr
    
    pnum = 1 # Process number to pass to thread to keep track of it
    processes = [] # List of running processes
    
    while curr_min >= min_denom:
        processes.append(Process(target=p71, args=(pnum, curr_min, curr_max)))
        processes[-1].start()
        
        pnum += 1
        curr_min -= incr
        curr_max -= incr
        
        if curr_min == 0:
            curr_min = 2
        
        if len(processes) >= max_processes:
            for p in processes:
                p.join()
            processes.clear()
    
    for p in processes:
        p.join()
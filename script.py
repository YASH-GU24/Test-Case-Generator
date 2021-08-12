import subprocess
import random

print("Running The Script.....")

x=1
while(x):
    #########################################################################
    #
    #                   WRITE INPUT FOR THE CASES HERE                       #
    # POINTS TO BE KEPT IN MIND :
    #### FILE WRITE METHOD TAKES STRING AS INPUT
    #### DONT FORGET TO PUT NEW LINE CHARACTER
    #### INPUT THE CONSTRAINTS BY PROVIDING RANGE TO RANDOM FUNCTION
    #### CLOSE THE INPUT FILE AFTER WRITING SO IT CAN BE READ BY THE PROGRAMME
    #### A SAMPLE IS GIVEN BELOW


    T=1                         # FOR TEST CASE TRY TO KEEP IT ONE TO MINIMISE WRITTING
    n = random.randint(1,10000) # ALTHOUGH YOU CAN PUT CONSTRAINTS AS BIG AS REQUIRED BUT TRY STARTING WITH SMALL    
    f = open("input.txt", "w")
    f.write(str(T))
    f.write("\n")
    f.write(str(n))
    f.close()

    #####################################################################################

    #DISPLAYING THE TEST CASE
    f=open("input.txt","r")
    i=f.read()
    print("THE TEST CASE IS:")
    print(i)
    f.close()
    

    #RUNNING BRUTE FORCE CODE
    subprocess.call(["g++", "brute_force.cpp"])
    subprocess.call("./a.exe")
    f=open("output1.txt","r")
    o1=f.read()
    f.close()
    print("OUTPUT FOR BRUTE FORCE CODE:")
    print(o1)

    #RUNNING OPTIMISED CODE
    subprocess.call(["g++", "optimised.cpp"])
    subprocess.call("./a.exe")
    f=open("output2.txt","r")
    o2=f.read()
    f.close()
    print("OUTPUT FOR OPTIMISED CODE:")
    print(o2)

    #CHECKING IF OUTPUT ARE SAME
    if(o1!=o2):
        print("OUTPUT MISMATCHED FOR ABOVE CASE")
        x=0
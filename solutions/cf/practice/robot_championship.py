"""
https://codeforces.com/problemset/problem/2273/B
*1900
constructive algorithms is such a weird problem topic. like, i thought i was cheesing it but online forums literally give "create a script to simulate small cases and literally try random stuff"
i literally found this by trying random stuff. see robot_championship_sim.py

after reading editorial:
NVM I ACTUALLY CHEESED IT LMAO
i thought two-colorability wasn't the solution, but damn
it was THREE COLORABILITY. that's actually so smart.
good problem.
"""
for t in range(int(input())):
    n = int(input())

    ans = []
    for i in range(2*n-1, 1, -2):
        ans.append(str(i))
    for i in range(2*n-2, 2, -2) if n%3 == 1 else range(2*n-1, 1, -2):
        ans.append(str(i))
    for i in range(2*n-1, 1, -2):
        ans.append(str(i))
    
    print(len(ans))
    print(' '.join(ans))
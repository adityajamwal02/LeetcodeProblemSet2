# Large Numbers : Deal with python easy:

class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        st=""
        for i in b:
            st=st+str(i)
        num=int(st)
        return (pow(a,num,1337))

class Solution(object):
    def largestTimeFromDigits(self, arr):
        s=""
        arr1=arr[:]
        for x in range(2,-1,-1):
            if x in arr:
                s+=str(x)
                arr.remove(x)
                break
        if len(s)>0 and s[0]=="2":
            for x in range(3,-1,-1):
                if x in arr:
                    s+=str(x)+":"
                    arr.remove(x)
                    break
        if len(s)>2:
            for x in range(5,-1,-1):
                if x in arr:
                    s+=str(x)
                    arr.remove(x)
                    break
        if len(s)>3:
            for x in range(9,-1,-1):
                if x in arr:
                    s+=str(x)
                    break
        if len(s)==5:
            return s
        a=""
        for x in range(1,-1,-1):
            if x in arr1:
                a+=str(x)
                arr1.remove(x)
                break
        if len(a)>0 and a[0] in "01":
            for x in range(9,-1,-1):
                if x in arr1:
                    a+=str(x)+":"
                    arr1.remove(x)
                    break
        if len(a)>2:
            for x in range(5,-1,-1):
                if x in arr1:
                    a+=str(x)
                    arr1.remove(x)
                    break
        if len(a)>3:
            for x in range(9,-1,-1):
                if x in arr1:
                    a+=str(x)
                    break
        return a if len(a)==5 else ""

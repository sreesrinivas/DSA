class Solution: 
    def pushDominoes(self, dominoes: str) -> str:

        prev = ''
        
        while dominoes != prev:
            prev = dominoes

            dominoes = (dominoes.replace('R.L', 'xxx')      # <-- 1)

                                .replace('R.' , 'RR' )      # <-- 2)         
                                .replace('.L' , 'LL' ))         

        return  dominoes.replace('xxx', 'R.L')              # <-- 3)

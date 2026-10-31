class Solution:
    def countOfAtoms(self, formula: str) -> str:
        scopes = [{}]
        i, n = 0, len(formula)

        def read_number():
            nonlocal i
            start = i
            while i < n and formula[i].isdigit():
                i += 1
            return int(formula[start:i]) if i > start else 1

        while i < n:
            if formula[i] == "(":
                scopes.append({})
                i += 1
            elif formula[i] == ")":
                i += 1
                multiplier = read_number()
                group = scopes.pop()
                for atom, count in group.items():
                    scopes[-1][atom] = scopes[-1].get(atom, 0) + count * multiplier
            else:
                start = i
                i += 1
                while i < n and formula[i].islower():
                    i += 1
                atom = formula[start:i]
                scopes[-1][atom] = scopes[-1].get(atom, 0) + read_number()

        return "".join(atom + (str(count) if count > 1 else "")
                       for atom, count in sorted(scopes[0].items()))

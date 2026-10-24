import pandas as pd

def employee_bonus(employee: pd.DataFrame, bonus: pd.DataFrame) -> pd.DataFrame:
    join_df=employee.merge(bonus,on="empId",how="left")
    sb=join_df["bonus"]<1000
    no_b=join_df["bonus"].isna()
    final=sb | no_b
    filter=join_df[final]
    out=filter.loc[:,["name","bonus"]]
    return out

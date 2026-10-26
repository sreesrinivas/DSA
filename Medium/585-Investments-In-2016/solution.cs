select round(sum(i1.tiv_2016)::numeric, 2) as tiv_2016 
from Insurance as i1
where 
    i1.tiv_2015 in (select i2.tiv_2015 from Insurance as i2 where i1.pid != i2.pid) 
    and (i1.lat, i1.lon) not in (select i3.lat, i3.lon from Insurance as i3 where i3.pid != i1.pid)

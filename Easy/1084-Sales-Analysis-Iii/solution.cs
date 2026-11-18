select s.product_id, product_name
from Sales s join Product p
on s.product_id = p.product_id
group by s.product_id
having  sum(sale_date < '2019-01-01' or sale_date > '2019-03-31') = 0

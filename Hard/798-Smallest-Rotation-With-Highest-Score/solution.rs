struct Fenwick {
    bits: Vec<i32>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Fenwick {
            bits: vec![0; n + 1 + 100000],
        }
    }

    pub fn add(&mut self, mut idx: i32, mut val: i32) {
        while idx < self.bits.len() as i32 {
            self.bits[idx as usize] += val as i32;
            idx += idx & -idx;
        }
    }
    
    pub fn search(&self, mut idx: i32) -> i32 {
        let mut res: i32 = 0;
        while idx > 0 {
            res += self.bits[idx as usize] as i32;
            idx -= idx & -idx;
        }
        return res;
    }
}

impl Solution {
    pub fn best_rotation(nums: Vec<i32>) -> i32 {
        let n: usize = nums.len();
        let mut nums1: Vec<i32> = Vec::new();
        let mut fenwick: Fenwick = Fenwick::new(n);
        
        for i in 0..n {
            nums1.push(nums[i]);
        }
        for i in 0..n {
            nums1.push(nums[i]);
        }

        let mut total: i32 = 0;
        
        for i in 0..n {
            let diff = (i as i32) - nums[i];
            if diff < 0 {
                continue;
            }
            fenwick.add(diff + 1, 1);
            total += 1;
            
        }
        
        let mut bestidx: i32 = 0;
        let mut bestnum: i32 = total - fenwick.search(0);
        
        for i in 1..n {
            let diffo = (i - 1) as i32 - nums1[i - 1];
            if diffo >= 0 {
               fenwick.add(diffo + 1, -1);
               total -= 1;
            }
            
            let diffi = (i + n - 1) as i32 - nums1[i + n - 1];
            if diffi >= 0 {
                fenwick.add(diffi + 1, 1);
                total += 1;
            }
            
            let mut res: i32 = total - fenwick.search(i as i32);
            if res > bestnum {
                bestnum = res;
                bestidx = i as i32;
            }
        }
        return bestidx;
    }
}

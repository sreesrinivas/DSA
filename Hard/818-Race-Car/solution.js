var racecar = function(target) {
	let dp=Array.from({length:10001}, x=>-1);
	return (function helper(t){
		if(dp[t]>0) return dp[t];
		let n=Math.ceil(Math.log(t+1)/Math.LN2); 
		// because t<=2^n-1, here n is the number of 'A' we used (no 'R‘’)
		if((1<<n)-1===t) dp[t]=n;
		else{
			dp[t]=helper((1<<n)-1-t)+n+1;
			// +n 'A' + 1 'R' === +n+1;
			// to reach the target, we may go as far as possible to just reach or pass the target
			// and then we take some steps back
			for(let r=0; r<n-1; r++){
				dp[t]=Math.min(dp[t], helper(t-(1<<(n-1))+(1<<r))+n+r+1);
				// (n-1) is the number of 'A' before the first 'R';
				// r is the number of 'A' after the first 'R' and before the second 'R';
				// and helper(...) return the number of steps after the second R;
				// +(n-1) 'A' + 1 'R' + r 'A' + 1 'R' === +n+r+1 (the number of steps before the second 'R'(including it))
				// for instance, to reach 5, we need to take 7 steps: AARARAA
				// to reach the target, we go as far as possible before passing the target (if we just reached it, we can stop)
				// and then we take some steps back (r steps back)
				// and then we continue going forward (by taking a 'R') and so on...
			}
		}
		return dp[t];
	})(target);
};

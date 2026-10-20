var canIWin = function(maxChoosableInteger, desiredTotal) {
    if (desiredTotal <= 0) return true;
    const sum = (maxChoosableInteger + 1) * maxChoosableInteger / 2;
    if (sum < desiredTotal) return false;

    const memo = new Map();

    const canWin = (used, total) => {
        if (memo.has(used)) return memo.get(used);

        for (let i = 1; i <= maxChoosableInteger; i++) {
            const mask = 1 << i;
            if ((used & mask) === 0) {
                if (i >= total || !canWin(used | mask, total - i)) {
                    memo.set(used, true);
                    return true;
                }
            }
        }

        memo.set(used, false);
        return false;
    };

    return canWin(0, desiredTotal);
};

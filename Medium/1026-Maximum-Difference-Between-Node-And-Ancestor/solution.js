function LowestFromChild(lowest, highest) {
    this.lowest = lowest;
    this.highest = highest;
}

var maxAncestorDiff = function(root) {
    let maxDiff = 0;
    performInorder(root);
    return maxDiff;

    function performInorder(root) {
        if (!root) return null;

        const left = performInorder(root.left);
        const right = performInorder(root.right);

        if (!left && !right) {
            return new LowestFromChild(root.val, root.val);
        }

        const diffWithLeftChild = !left ?
            0 :
            Math.max(Math.abs(root.val - left.lowest), Math.abs(root.val - left.highest));

        const diffWithRightChild = !right ?
            0 :
            Math.max(Math.abs(root.val - right.lowest), Math.abs(root.val - right.highest));

        const currMaxDiff = Math.max(diffWithLeftChild, diffWithRightChild);
        maxDiff = Math.max(maxDiff, currMaxDiff);

        const leftLowest = left ? left.lowest : Number.MAX_SAFE_INTEGER;
        const leftHighest = left ? left.highest : Number.MIN_SAFE_INTEGER;
        const rightLowest = right ? right.lowest : Number.MAX_SAFE_INTEGER;
        const rightHighest = right ? right.highest : Number.MIN_SAFE_INTEGER;

        const lowestAtCurrNode = Math.min(root.val, Math.min(leftLowest, rightLowest));
        const highestAtCurrNode = Math.max(root.val, Math.max(leftHighest, rightHighest));

        return new LowestFromChild(lowestAtCurrNode, highestAtCurrNode);
    }
};

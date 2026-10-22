class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inorder(root):
    if not root:
        return []
    result = []
    result += inorder(root.left)
    result.append(root.val)
    result += inorder(root.right)
    return result

def preorder(root):
    if not root:
        return []
    result = []
    result.append(root.val)
    result += preorder(root.left)
    result += preorder(root.right)
    return result

def postorder(root):
    if not root:
        return []
    result = []
    result += postorder(root.left)
    result += postorder(root.right)
    result.append(root.val)
    return result

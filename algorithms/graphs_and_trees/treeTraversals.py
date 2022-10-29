from collections import deque

class TreeNode:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

'''
Inorder => Left, Root, Right.

Preorder => Root, Left, Right.

Post order => Left, Right, Root.
'''

class Traversals:
    # Essentially a breadth first search. However, we're just checking if there are left and right nodes.
    def lvlOrder(self, root: TreeNode):
        queue = []
        queue.append(root)
        while queue:
            tmp = queue.pop()
            print(tmp.data, end =' ')

            if tmp.left:
                queue.append(tmp.left)
            if tmp.right:
                queue.append(tmp.right)

        if root is None:
            return
    '''
            def preorderTraversal(self, root):
        stack = []
        while stack or root:
            if root:
                stack.append(root)
                res.append(root.val)    
                root = root.left     
            else:
                node = stack.pop()
                root = node.right
        return res
    '''

    # A quintessential DFS
    def preOrder(self, root: TreeNode):
        if root is None:
            return

        stack = []
        stack.append(root)

        while stack:
            curr = stack.pop()
            print(curr.data, end=" ")

            if curr.right:
                stack.append(curr.right)
            if curr.left:
                stack.append(curr.left)

    def postOrder(self, root):
        if root is None:
            return
        stack, track = [], []
        while stack or root:
            if root:
                stack.append(root)
                track.append(root.data)
                root = root.right
            else:
                tmp = stack.pop()
                root = tmp.left
        print(track[::-1], end=" ")

    def inOrder(self, root):
        if root is None:
            return
        stack = []
        tmp = root
        while stack or tmp:
            if tmp:
                stack.append(tmp)
                tmp = tmp.left
            else:
                tmp = stack.pop()
                print(tmp.data, end=" ")
                tmp = tmp.right


def main():
    '''
        5
      3   8
    1  4 6 10
   0 2   7  9
    '''
    root = TreeNode(5)
    root.left = TreeNode(3)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(4)
    root.left.left.left = TreeNode(0)
    root.left.left.right = TreeNode(2)
    root.right = TreeNode(8)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(10)
    root.right.left.right = TreeNode(7)
    root.right.right.left = TreeNode(9)

    x = Traversals()
    x.preOrder(root) # 
    print("\n")
    x.postOrder(root)
    print("\n")
    x.inOrder(root)

main()

class TreeNode:
    def __init__(self, k, v):
        self.key = k
        self.value = v
        self.left = None
        self.right = None
        self.parent = None
        self.height = 1
        self.num_left = 1
        self.num_total = 1
 
 
class AvlTree:
 
    def __init__(self):
        self._tree = None
 
    def add(self, k, v):
        if not self._tree:
            self._tree = TreeNode(k, v)
            return
        node = self._add(k, v)
        if node:
            self._rebalance(node)
 
    def _add(self, k, v):
        node = self._tree
        while node:
            if k < node.key:
                if node.left:
                    node = node.left
                else:
                    node.left = TreeNode(k, v)
                    node.left.parent = node
                    return node.left
            elif node.key < k:
                if node.right:
                    node = node.right
                else:
                    node.right = TreeNode(k, v)
                    node.right.parent = node
                    return node.right
            else:
                node.value = v
                return
 
    @staticmethod
    def get_height(x):
        return x.height if x else 0
 
    @staticmethod
    def get_num_total(x):
        return x.num_total if x else 0
 
    def _rebalance(self, node):
 
        n = node
        while n:
            lh = self.get_height(n.left)
            rh = self.get_height(n.right)
            n.height = max(lh, rh) + 1
            balance_factor = lh - rh
            n.num_total = 1 + self.get_num_total(n.left) + self.get_num_total(n.right)
            n.num_left = 1 + self.get_num_total(n.left)
 
            if balance_factor > 1:
                if self.get_height(n.left.left) < self.get_height(n.left.right):
                    self._rotate_left(n.left)
                self._rotate_right(n)
            elif balance_factor < -1:
                if self.get_height(n.right.right) < self.get_height(n.right.left):
                    self._rotate_right(n.right)
                self._rotate_left(n)
            else:
                n = n.parent
 
    def _remove_one(self, node):
        """
        Side effect!!! Changes node. Node should have exactly one child
        """
        replacement = node.left or node.right
        if node.parent:
            if AvlTree._is_left(node):
                node.parent.left = replacement
            else:
                node.parent.right = replacement
            replacement.parent = node.parent
            node.parent = None
        else:
            self._tree = replacement
            replacement.parent = None
        node.left = None
        node.right = None
        node.parent = None
        self._rebalance(replacement)
 
    def _remove_leaf(self, node):
        if node.parent:
            if AvlTree._is_left(node):
                node.parent.left = None
            else:
                node.parent.right = None
            self._rebalance(node.parent)
        else:
            self._tree = None
        node.parent = None
        node.left = None
        node.right = None
 
    def remove(self, k):
        node = self._get_node(k)
        if not node:
            return
        if AvlTree._is_leaf(node):
            self._remove_leaf(node)
            return
        if node.left and node.right:
            nxt = AvlTree._get_next(node)
            node.key = nxt.key
            node.value = nxt.value
            if self._is_leaf(nxt):
                self._remove_leaf(nxt)
            else:
                self._remove_one(nxt)
            self._rebalance(node)
        else:
            self._remove_one(node)
 
    def get(self, k):
        node = self._get_node(k)
        return node.value if node else -1
 
    def _get_node(self, k):
        if not self._tree:
            return None
        node = self._tree
        while node:
            if k < node.key:
                node = node.left
            elif node.key < k:
                node = node.right
            else:
                return node
        return None
 
    def get_at(self, pos):
        x = pos + 1
        node = self._tree
        while node:
            if x < node.num_left:
                node = node.left
            elif node.num_left < x:
                x -= node.num_left
                node = node.right
            else:
                return (node.key, node.value)
        raise IndexError("Out of ranges")
 
    @staticmethod
    def _is_left(node):
        return node.parent.left and node.parent.left == node
 
    @staticmethod
    def _is_leaf(node):
        return node.left is None and node.right is None
 
    def _rotate_right(self, node):
        if not node.parent:
            self._tree = node.left
            node.left.parent = None
        elif AvlTree._is_left(node):
            node.parent.left = node.left
            node.left.parent = node.parent
        else:
            node.parent.right = node.left
            node.left.parent = node.parent
        bk = node.left.right
        node.left.right = node
        node.parent = node.left
        node.left = bk
        if bk:
            bk.parent = node
        node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1
        node.num_total = 1 + self.get_num_total(node.left) + self.get_num_total(node.right)
        node.num_left = 1 + self.get_num_total(node.left)
 
    def _rotate_left(self, node):
        if not node.parent:
            self._tree = node.right
            node.right.parent = None
        elif AvlTree._is_left(node):
            node.parent.left = node.right
            node.right.parent = node.parent
        else:
            node.parent.right = node.right
            node.right.parent = node.parent
        bk = node.right.left
        node.right.left = node
        node.parent = node.right
        node.right = bk
        if bk:
            bk.parent = node
        node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1
        node.num_total = 1 + self.get_num_total(node.left) + self.get_num_total(node.right)
        node.num_left = 1 + self.get_num_total(node.left)
 
    @staticmethod
    def _get_next(node):
        if not node.right:
            return node.parent
        n = node.right
        while n.left:
            n = n.left
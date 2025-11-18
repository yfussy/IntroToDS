int level(node *n, KeyT &min, int &diff) {
    if (!n) return -1;

    int lh = level(n->left, min, diff);
    int rh = level(n->right, min, diff);

    if (lh != rh) {
        int curDiff = std::abs(lh - rh);
        if (curDiff > diff) {
            min = n->data.first;
            diff = curDiff;
        } else if (curDiff == diff) {
            min = std::min(n->data.first, min);
        }
    }
    
    return std::max(lh, rh) + 1;
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    KeyT min = mRoot->data.first;
    int diff = 0;
    level(mRoot, min, diff);
    return min;
}

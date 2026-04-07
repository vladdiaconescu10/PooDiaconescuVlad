#pragma once
#pragma once

template <typename T>
class TreeNode {
public:
    T value;
    TreeNode** children;
    int children_count;
    int children_capacity;

    TreeNode(T val) {
        value = val;
        children_count = 0;
        children_capacity = 2;
        children = new TreeNode * [children_capacity];
    }

    ~TreeNode() {
        delete[] children;
    }

    void add_child(TreeNode* child) {
        if (children_count == children_capacity) {
            children_capacity *= 2;
            TreeNode** new_children = new TreeNode * [children_capacity];
            for (int i = 0; i < children_count; i++) {
                new_children[i] = children[i];
            }
            delete[] children;
            children = new_children;
        }
        children[children_count++] = child;
    }
};

template <typename T>
class Tree {
private:
    TreeNode<T>* root;

    void clear(TreeNode<T>* node) {
        if (!node) return;
        for (int i = 0; i < node->children_count; i++) {
            clear(node->children[i]);
        }
        delete node;
    }

    TreeNode<T>* find_helper(TreeNode<T>* node, T val, bool (*cmp)(T, T)) {
        if (!node) return nullptr;
        if (cmp ? cmp(node->value, val) : (node->value == val)) return node;
        for (int i = 0; i < node->children_count; i++) {
            TreeNode<T>* res = find_helper(node->children[i], val, cmp);
            if (res) return res;
        }
        return nullptr;
    }

    int count_helper(TreeNode<T>* node) {
        if (!node) return 0;
        int c = 1;
        for (int i = 0; i < node->children_count; i++) {
            c += count_helper(node->children[i]);
        }
        return c;
    }

    void sort_helper(TreeNode<T>* node, bool (*cmp)(T, T)) {
        if (!node) return;
        for (int i = 0; i < node->children_count - 1; i++) {
            for (int j = i + 1; j < node->children_count; j++) {
                bool swap_needed = cmp ? cmp(node->children[i]->value, node->children[j]->value)
                    : (node->children[i]->value > node->children[j]->value);
                if (swap_needed) {
                    TreeNode<T>* temp = node->children[i];
                    node->children[i] = node->children[j];
                    node->children[j] = temp;
                }
            }
        }
        for (int i = 0; i < node->children_count; i++) {
            sort_helper(node->children[i], cmp);
        }
    }

    TreeNode<T>* find_parent(TreeNode<T>* current, TreeNode<T>* target) {
        if (!current) return nullptr;
        for (int i = 0; i < current->children_count; i++) {
            if (current->children[i] == target) return current;
            TreeNode<T>* res = find_parent(current->children[i], target);
            if (res) return res;
        }
        return nullptr;
    }

public:
    Tree() {
        root = nullptr;
    }

    ~Tree() {
        clear(root);
    }

    TreeNode<T>* add_node(TreeNode<T>* parent, T value) {
        TreeNode<T>* new_node = new TreeNode<T>(value);
        if (!parent) {
            if (!root) {
                root = new_node;
            }
            else {
                delete new_node;
                return nullptr;
            }
        }
        else {
            parent->add_child(new_node);
        }
        return new_node;
    }

    TreeNode<T>* get_node(TreeNode<T>* parent) {
        return parent;
    }

    void delete_node(TreeNode<T>* node) {
        if (!node) return;
        if (node == root) {
            clear(root);
            root = nullptr;
            return;
        }
        TreeNode<T>* parent = find_parent(root, node);
        if (parent) {
            for (int i = 0; i < parent->children_count; i++) {
                if (parent->children[i] == node) {
                    for (int j = i; j < parent->children_count - 1; j++) {
                        parent->children[j] = parent->children[j + 1];
                    }
                    parent->children_count--;
                    break;
                }
            }
        }
        clear(node);
    }

    TreeNode<T>* find(T val, bool (*cmp)(T, T) = nullptr) {
        return find_helper(root, val, cmp);
    }

    TreeNode<T>* insert(TreeNode<T>* parent, T value, int index) {
        if (!parent) return nullptr;
        TreeNode<T>* new_node = new TreeNode<T>(value);
        if (parent->children_count == parent->children_capacity) {
            parent->children_capacity *= 2;
            TreeNode<T>** new_children = new TreeNode<T>*[parent->children_capacity];
            for (int i = 0; i < parent->children_count; i++) {
                new_children[i] = parent->children[i];
            }
            delete[] parent->children;
            parent->children = new_children;
        }
        if (index > parent->children_count) index = parent->children_count;
        for (int i = parent->children_count; i > index; i--) {
            parent->children[i] = parent->children[i - 1];
        }
        parent->children[index] = new_node;
        parent->children_count++;
        return new_node;
    }

    void sort(TreeNode<T>* node = nullptr, bool (*cmp)(T, T) = nullptr) {
        if (!node) node = root;
        sort_helper(node, cmp);
    }

    int count(TreeNode<T>* node = nullptr) {
        if (!node) {
            if (!root) return 0;
            return count_helper(root);
        }
        return count_helper(node);
    }
};
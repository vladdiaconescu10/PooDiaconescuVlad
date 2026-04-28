#pragma once
#pragma once

template <typename K, typename V>
class Map {
private:
    struct Element {
        K key;
        V value;
    };

    Element* elements;
    int capacity;
    int count;

    void resize() {
        capacity *= 2;
        Element* new_elements = new Element[capacity];
        for (int i = 0; i < count; i++) {
            new_elements[i] = elements[i];
        }
        delete[] elements;
        elements = new_elements;
    }

public:
    Map() {
        capacity = 10;
        count = 0;
        elements = new Element[capacity];
    }

    ~Map() {
        delete[] elements;
    }

    V& operator[](const K& key) {
        for (int i = 0; i < count; i++) {
            if (elements[i].key == key) {
                return elements[i].value;
            }
        }
        if (count == capacity) {
            resize();
        }
        elements[count].key = key;
        return elements[count++].value;
    }

    void Set(const K& key, const V& value) {
        (*this)[key] = value;
    }

    bool Get(const K& key, V& value) const {
        for (int i = 0; i < count; i++) {
            if (elements[i].key == key) {
                value = elements[i].value;
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return count;
    }

    void Clear() {
        count = 0;
    }

    bool Delete(const K& key) {
        for (int i = 0; i < count; i++) {
            if (elements[i].key == key) {
                for (int j = i; j < count - 1; j++) {
                    elements[j] = elements[j + 1];
                }
                count--;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& map) const {
        for (int i = 0; i < map.count; i++) {
            bool found = false;
            for (int j = 0; j < count; j++) {
                if (elements[j].key == map.elements[i].key) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }

    struct Tuple {
        K key;
        V value;
        int index;
    };

    struct Iterator {
        Element* ptr;
        int index;

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }

        void operator++() {
            ptr++;
            index++;
        }

        Tuple operator*() const {
            return { ptr->key, ptr->value, index };
        }
    };

    Iterator begin() const {
        return { elements, 0 };
    }

    Iterator end() const {
        return { elements + count, count };
    }
};
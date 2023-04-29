class sectionA {
    String name;
    int roll;
    double cgpa;

    sectionA(String name, int roll, double cgpa) {
        this.name = name;
        this.roll = roll;
        this.cgpa = cgpa;
    }
}

class Array_base_BST {
    private sectionA[] tree;
    private int size;

    public Array_base_BST(int capacity) {
        this.tree = new sectionA[capacity];
        this.size = 0;
    }

    public boolean isEmpty() {
        return tree[0] == null;
    }

    private int leftChildIdx(int i) {
        return 2 * i + 1;
    }

    private int rightChildIdx(int i) {
        return 2 * i + 2;
    }

    private int parent(int i) {
        return (i - 1) / 2;
    }

    public void insert(sectionA stu) {
        if (tree[tree.length - 1] != null)
            return;
        if (isEmpty()) {
            tree[0] = stu;
        } else {
            int currentIndex = 0;
            while (true) {
                if (stu.cgpa < tree[currentIndex].cgpa) {
                    int leftChildIndex = leftChildIdx(currentIndex);
                    if (leftChildIndex >= tree.length)
                        return;
                    if (tree[leftChildIndex] == null) {
                        tree[leftChildIndex] = stu;
                        break;
                    } else {
                        currentIndex = leftChildIndex;
                    }
                } else {
                    int rightChildIndex = rightChildIdx(currentIndex);
                    if (rightChildIndex >= tree.length)
                        return;
                    if (tree[rightChildIndex] == null) {
                        tree[rightChildIndex] = stu;
                        break;
                    } else {
                        currentIndex = rightChildIndex;
                    }
                }
            }
        }
        size++;
    }

    void inorder(int currentIndex) {
        if (currentIndex >= tree.length || tree[currentIndex] == null)
            return;
        inorder(leftChildIdx(currentIndex));
        System.out.println("ROLL : " + tree[currentIndex].roll + " NAME :" + tree[currentIndex].name + " CGPA :"
                + tree[currentIndex].cgpa);
        inorder(rightChildIdx(currentIndex));
    }

    public boolean search(int roll) {
        int currentIndex = 0;
        while (currentIndex < tree.length && tree[currentIndex] != null) {
            if (roll == tree[currentIndex].roll)
                return true;
            else if (roll < tree[currentIndex].roll)
                currentIndex = leftChildIdx(currentIndex);
            else
                currentIndex = rightChildIdx(currentIndex);
        }
        return false;
    }

    private int inorderSuccessorIndex(int currentIndex) {
        int successorIndex = rightChildIdx(currentIndex);
        while (tree[leftChildIdx(successorIndex)] != null)
            successorIndex = leftChildIdx(successorIndex);
        return successorIndex;
    }

    public void delete(double cgpa) {
        if (isEmpty())
            return;
        int currentIndex = 0;
        int parentIndex = -1;
        while (currentIndex < tree.length && tree[currentIndex] != null) {
            if (cgpa == tree[currentIndex].cgpa) {
                if (tree[leftChildIdx(currentIndex)] == null && tree[rightChildIdx(currentIndex)] == null)
                    tree[currentIndex] = null;
                else if (tree[leftChildIdx(currentIndex)] != null && tree[rightChildIdx(currentIndex)] == null) {
                    tree[currentIndex] = tree[leftChildIdx(currentIndex)];
                    tree[leftChildIdx(currentIndex)] = null;
                } else if (tree[leftChildIdx(currentIndex)] == null && tree[rightChildIdx(currentIndex)] != null) {
                    tree[currentIndex] = tree[rightChildIdx(currentIndex)];
                    tree[rightChildIdx(currentIndex)] = null;
                } else {
                    int successorIndex = inorderSuccessorIndex(currentIndex);
                    sectionA successorValue = tree[successorIndex];
                    delete(successorValue.cgpa);
                    tree[currentIndex] = successorValue;
                }
                size--;
                return;
            } else if (cgpa < tree[currentIndex].cgpa) {
                parentIndex = currentIndex;
                currentIndex = leftChildIdx(currentIndex);
            } else {
                parentIndex = currentIndex;
                currentIndex = rightChildIdx(currentIndex);
            }
        }
    }
}

public class testy {
    public static void main(String[] args) {
        sectionA[] sec = new sectionA[11];
        sec[0] = new sectionA("Dibbyo", 28, 3.76);
        sec[1] = new sectionA("Abir", 36, 3.56);
        sec[2] = new sectionA("Shawn", 47, 3.44);
        sec[3] = new sectionA("Rifat", 24, 3.88);
        sec[4] = new sectionA("Asif", 54, 3.22);
        sec[5] = new sectionA("Meherun", 5, 3.91);
        sec[6] = new sectionA("Lubaina", 14, 3.86);
        sec[7] = new sectionA("Tajri", 41, 3.77);
        sec[8] = new sectionA("Fahim", 6, 3.67);
        sec[9] = new sectionA("Himel", 14, 4.00);
        sec[10] = new sectionA("Tasnia", 27, 3.96);
        Array_base_BST bst = new Array_base_BST(1000);
        for (int i = 0; i < 11; i++)
            bst.insert(sec[i]);
        // bst.inorder(0);
        // for (sectionA se:sec) System.out.println(se.name+" "+se.cgpa+" "+se.roll);
        bst.delete(3.22);
        bst.inorder(0);
    }
}

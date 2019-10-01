import java.util.Arrays;
import java.util.List;

class GnomeSort  { 
	static <T> boolean swap(T[] array, int idx, int idy) {
        T swap = array[idx];
        array[idx] = array[idy];
        array[idy] = swap;
        return true;
    }

    static <T extends Comparable<T>> boolean less(T v, T w) {
        return v.compareTo(w) < 0;
    }

    static void print(List<?> toPrint) {
        toPrint.stream()
                .map(Object::toString)
                .map(str -> str + " ")
                .forEach(System.out::print);

        System.out.println();
    }

    static void print(Object[] toPrint) {
        System.out.println(Arrays.toString(toPrint));
    }

    static <T extends Comparable<T>> void flip(T[] array, int left, int right) {
        while (left <= right) {
            swap(array, left++, right--);
        }
    }

    public <T extends Comparable<T>> T[] sort(T[] arr) {
        int i = 1;
        int j = 2;
        while (i < arr.length) {
            if (less(arr[i - 1], arr[i])) i = j++;
            else {
                swap(arr, i - 1, i);
                if (--i == 0) {
                    i = j++;
                }
            }
        }

        return null;
    }

    public static void main(String[] args) {
        Integer[] integers = {4, 3, 6, 78, 1, 26, 23, 23, 0, -6, 7, 584, 31, 90, 12};
        String[] strings = {"g", "r", "a", "t", "y", "dd", "da", "zz", "AA", "aa", "aB", "Hb", "Z"};
        GnomeSort gnomeSort = new GnomeSort();

        gnomeSort.sort(integers);
        gnomeSort.sort(strings);

        System.out.println("After sort : ");
        print(integers);
        print(strings);


    }
}

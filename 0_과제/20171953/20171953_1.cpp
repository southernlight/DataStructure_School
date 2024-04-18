#include <iostream>
using namespace std;

template <class T> class Rectangle
{
  private:
    T x_left, y_left;   //좌상단
    T x_right, y_right; //우하단

  public:
    Rectangle(T x_l, T y_l, T x_r, T y_r)
    {
        x_left = x_l;
        y_left = y_l;
        x_right = x_r;
        y_right = y_r;
    }

    T get_xl()
    {
        return x_left;
    }

    T get_yl()
    {
        return y_left;
    }
    T get_xr()
    {
        return x_right;
    }
    T get_yr()
    {
        return y_right;
    }

    void set_xl(T x)
    {
        x_left = x;
    }
    void set_yl(T y)
    {
        y_left = y;
    }
    void set_xr(T x)
    {
        x_right = x;
    }
    void set_yr(T y)
    {
        y_right = y;
    }

    int area()
    {
        T x_len = x_right - x_left;
        T y_len = y_left - y_right;
        return x_len * y_len;
    }

    bool operator<(Rectangle &other)
    {
        return area() < other.area();
    }

    Rectangle &operator=(Rectangle &other)
    {
        x_left = other.get_xl();
        y_left = other.get_yl();
        x_right = other.get_xr();
        y_right = other.get_yr();
        return *this;
    }
};
template <class T> void swap(T &a, T &b);
template <class T> void SelectionSort(T *rectangles, const int n);
template <class T> void print_areas(Rectangle<T> *rectangles, const int n);

int main()
{
    const int n = 10;
    Rectangle<int> rectangles[n] = {Rectangle(1, 4, 5, 2), Rectangle(3, 6, 8, 3), Rectangle(2, 5, 7, 1),
                                    Rectangle(4, 3, 9, 2), Rectangle(2, 7, 6, 5), Rectangle(5, 5, 8, 2),
                                    Rectangle(1, 2, 6, 1), Rectangle(3, 4, 7, 2), Rectangle(2, 3, 5, 1),
                                    Rectangle(1, 3, 4, 1)};
    cout << "Before Sorting: ";
    print_areas(rectangles, n);
    SelectionSort(rectangles, n);
    cout << "After Sorting: ";
    print_areas(rectangles, n);

    return 0;
}
template <class T> void swap(T &a, T &b)
{
    T temp = a;
    temp = a;
    a = b;
    b = temp;
}
template <class T> void SelectionSort(T *a, const int n)
{

    for (int i = 0; i < n; i++)
    {
        int j = i;
        for (int k = i + 1; k < n; k++)
            if (a[k] < a[j])
                j = k;
        swap(a[i], a[j]);
    }
}

template <class T> void print_areas(Rectangle<T> *rectangles, const int n)
{
    for (int i = 0; i < n; i++)
        cout << rectangles[i].area() << " ";
    cout << "\n";
}
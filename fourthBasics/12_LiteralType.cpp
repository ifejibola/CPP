

// A user-defined type used in a constant expression.
struct Point
{
    int x, y, z;
    constexpr Point up(int d) { return {x, y, z + d}; };
    constexpr Point move(int dx, int dy) { return {x + dx, y + dy}; };
};
/*
    * A class with a constexpr constructor is called a literal type. To be simple enough to be
    constexpr, a constructor must have an empty body and all members must be initialized
    by potentially constant expression. EXAMPLE :

*/

constexpr Point origo{0, 0};
constexpr int z = origo.x;

constexpr Point a[] = {
    origo, Point{1, 1}, Point{2, 2}, origo.move(3, 3)};

constexpr int x = a[1].x;       // x becomes 1
constexpr Point xy{0, sqrt(2)}; // ERROR: sqr(2) is not a constant expression

/*
    * Note that we can have constexpr arrays and also access array elements and obejct members.
    * Naturally, we can define constexpr functions to take arguments of literal types.
*/

constexpr int sqaure(int x)
{
    return x * x;
};

constexpr int radical_distance(Point p)
{
    return isqrt(sqaure(p.x) + sqaure(p.y) + sqaure(p.z));
};

constexpr Point p1{10, 20, 30}; // the default constructor is constexpr
constexpr p2{p1.up(20)};        // Point :: up() is constexpr
constexpr int dist = radical_distance(p2);

// ALL EXAMPLE CODE, LOGIC READ THE CODE!! Some of the code shouldnt be givng error eg line 20 is correct but type error(investigate)
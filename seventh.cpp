#include <cilk/reducer.h> class point
{
};
class point_holder
{
struct Monoid: cilk::monoid_base<point>
{
static void reduce (point *left, point *right) {}
};
private: cilk::reducer<Monoid> imp_; public:
point_holder() : imp_() {} void set(int x, int y) { point &p = imp_.view(); p.set(x, y); 
}
bool is_valid() { return imp_.view().is_valid(); } int x() { return imp_.view().x(); }
int y() { return imp_.view().y(); }
};

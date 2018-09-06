#ifndef POINT_HEADER
#define POINT_HEADER
namespace ppc {

class point {
  public:
    point();
    point(int t_x, int t_y);

    // TODO: add + - == < > += -= >= <= ostream<< operator overloads

    const int x;
    const int y;
};

} // namespace ppc
#endif // POINT_HEADER
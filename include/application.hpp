#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER
#include <vector>

namespace ppc {

class Application {
 public:
  Application();

 private:
  std::vector<Window> windows_;
};

}  // namespace ppc

#endif  // APPLICATION_HEADER
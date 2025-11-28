#include <ctime>
#include <iostream>
#include <memory>

class Counter {
  public:
    void TimeMeter(unsigned count);

    double setTimeStamp(unsigned num);

    double getSTimeStamp(unsigned num);
    int64_t getMSTimeStamp(unsigned num);

    double getSDiff(unsigned first, unsigned second);
    int64_t getMSDiff(unsigned first, unsigned second);

    bool isLess(unsigned first, unsigned second, int64_t expected);
    bool isLess(unsigned num, int64_t expected);

  private:
  class Impl;
  std::unique_ptr<Impl> impl_;

};
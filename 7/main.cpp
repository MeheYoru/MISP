#include <bits/stdc++.h>

class TimeMeter
{
public:
    using Clock = std::chrono::high_resolution_clock;
    TimeMeter() : start(Clock::now()) {}
    double elapsed_ms() const
    {
        auto end = Clock::now();
        return std::chrono::duration<double, std::milli>(end - start).count();
    }

private:
    Clock::time_point start;
};

template <typename Func, typename... Args>
double measure_time(Func f, Args &&...args)
{
    const int REPEAT = 999;
    TimeMeter tm;
    for (int i = 0; i < REPEAT; i++)
        f(std::forward<Args>(args)...);
    return tm.elapsed_ms();
}

void multiply_by(std::vector<long long> &v, long long factor)
{
    for (long long &x : v)
        x *= factor;
}

int main()
{
    std::vector<long long> v(67676);
    for (long long i = 0; i < 67676; ++i)
        v[i] = i + 1;

    std::vector<long long> powered(v.size());

    auto square = std::bind(std::multiplies<long long>(), std::placeholders::_1, std::placeholders::_1);
    auto cube = [&](long long x)
    { return square(x) * x; };

    std::transform(v.begin(), v.end(), powered.begin(), cube);

    auto lambda = [&](std::vector<long long> &a)
    {
        for (long long &x : a)
            x += 10;
    };

    std::cout << std::fixed << std::setprecision(6);

    double t1 = measure_time(lambda, std::ref(v));
    std::cout << "Lambda time: " << t1 << " ms\n";

    auto bound_func = std::bind(multiply_by, std::placeholders::_1, 5LL);
    double t2 = measure_time(bound_func, std::ref(v));
    std::cout << "std::bind time: " << t2 << " ms\n";

    return 0;
}

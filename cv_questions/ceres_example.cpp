#include <ceres.h>

// ========================Simple Example=======================================
// Assuming we have an equation
// y = exp(a*x^2 + b*x + c)
// cost function is
// | y - exp(a*x^2 + b*x + c) |

struct CostFunction
{
    CostFunction(double x, double y) : _x(x), _y(y) {}
    
    template <typename T>
    bool operator() (const T* abc, const T* residual) const
    {
        residual[0] = T(_y) - ceres::exp(abc[0] * x * x + abc[1] * x + abc[2]);
        return true;
    }

    const double _x, _y;
};

int main()
{
    // Prepare data
    int N = 100;                        // number of data points
    double sigma = 1.0;                 // sigma of noise
    double a = 1.0, b = 2.0, c = 3.0;   // ground truth params
    vector<double> x_data(N), y_dat(N); // synthetic data
    cv::RNG rng;                        // random number generator

    for (int i = 0; i < N; ++i)
    {
        x_data[i] = i / 100;
        y_data[i] = exp(abc[0]*x*x + abc[1]*x + abc[2]) + rng.gaussian(sigma);
    }

    // Build the problem
    ceres::Problem problem;

    // Parameters
    double abc[3] = {0.0, 0.0, 0.0};    // parameters to be optimized

    // Add costs to the problem
    for (int i = 0; i < N; ++i)
    {
        ceres::CostFunction* cost_function =
            new ceres::AutoDiffCostFunction<CostFunction, 1, 3>(new CostFunction(x_data[i], y_data[i]));
        problem.AddResidualBlock(cost_function, nullptr, abc);
    }

    // Run the solver
    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    std::cout << summary.BriefReport() << std::endl;
    std::cout << abc[0] << ", " << abc[1] << ", " << abc[2] << std::endl;
}
// =============================================================================

// =================================Practical===================================
class ReprojectionError
{
    const CameraIntrinsics params;
    Eigen::Vector2d uv;

public:
    ReprojectionError(const CameraIntrinsics _params, Eigen::Vector2d _uv) : params(_params), uv(_uv) {}

    template <typename T>
    bool operator() (const T* pt, T* residual) const
    {
        residual = CameraProject(pt, params) - uv;
        return true;
    }

    static ceres::CostFunction* create(const CameraIntrinsics params, const Eigen::Vector2d uv)
    {
        ReprojectionError* error = new ReprojectionError(params, uv);
        return new ceres::AutoDiffCostFunction<ReprojectionError, 2, 2>(error);
    }
};

int main()
{
    ceres::Problem problem;
    double xy[N];
    for (size_t i = 0; i < N; ++i)
    {
        ceres::CostFunction* cost = ReprojectionError.create(intrinsics, uvs[i]);
        problem.AddResidualBlock(cost, nullptr, xy[i]);
    }

    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    std::cout << summary.BriefReport() << std::endl;
    
}
// =============================================================================
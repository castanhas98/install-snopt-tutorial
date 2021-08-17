#include <pagmo/algorithm.hpp>
#include <pagmo/archipelago.hpp>
#include <pagmo/problem.hpp>
#include <pagmo/problems/rosenbrock.hpp>
#include <pagmo_plugins_nonfree/pagmo_plugins_nonfree.hpp>

using namespace pagmo;


int main()
{

    problem prob{rosenbrock(30)};
    
    // Instantiate a pagmo_plugins_nonfree algorithm, in this case SNOPT. This assumes a library libsnopt7_c.so is
    // found in the path "/usr/local/lib/". Otherwise you will get a runtime error.
    // Default values -> ppnf::snopt7(bool screen_output = false, std::string snopt7_c_library = "/usr/local/lib/libsnopt7_c.so", unsigned minor_version = 6u);
    algorithm algo(ppnf::snopt7(false, "/absolute/path/to/install-snopt-tutorial/snopt-interface/lib/libsnopt7_c.so", 6u));

    population pop( prob, 1, 0 );

    std::cout << "Initial Population:" << std::endl;
    std::cout << pop << std::endl;

    pop = algo.evolve( pop );

    std::cout << "Final Population:" << std::endl;
    std::cout << pop << std::endl;

    /*
    *   Example code provided in https://esa.github.io/pagmo_plugins_nonfree/quickstart.html below
    */

    // // 1 - Instantiate a pagmo problem constructing it from the Rosenbrock
    // // UDP (user defined problem).
    // problem prob{rosenbrock(30)};

    // // 2 - Instantiate a pagmo_plugins_nonfree algorithm, in this case SNOPT. This assumes a library libsnopt7_c.so is
    // // found in the path "/usr/local/lib/". Otherwise you will get a runtime error.
    // // Can be a relative path.
    // algorithm algo(ppnf::snopt7(true, "/absolute/path/to/install-snopt-tutorial/snopt-interface/lib/libsnopt7_c.so", 6u));
    // // 3 - Instantiate an archipelago with 16 islands having each 1 individual (the initial guess)
    // archipelago archi{16, algo, prob, 1};
    
    // archipelago archi1 = archi;

    // // 4 - Run the snopt7 calls in parallel on the 16 separate islands.
    // archi.evolve(10);

    // // 5 - Wait for the snopt7 calls to be finished
    // archi.wait();

    // // 6 - Print the fitness of the best solution in each island
    // for (const auto &isl : archi) {
    //     print(isl.get_population().champion_f(), "\n");
    // }
    
    // for (const auto &isl : archi1) {
    //     print(isl.get_population().champion_f(), "\n");
    // }

    return 0;
}

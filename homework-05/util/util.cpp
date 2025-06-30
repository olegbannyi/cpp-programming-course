#include "util.h"
#include <cstring>
namespace banking
{
namespace util
{
bool is_reference_mode(int argc, char **argv)
{
    const char *ref_mode = "--ref";

    if (argc < 2)
    {
        return false;
    }

    for (int i = 1; i < argc; ++i)
    {
        if (std::strcmp(ref_mode, argv[i]) == 0)
        {
            return true;
        }
    }

    return false;
}
} // namespace util
} // namespace banking

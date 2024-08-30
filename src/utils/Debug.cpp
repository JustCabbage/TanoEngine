#include "Debug.hpp"

namespace Tano
{
    void Debug::HandleAssert(const std::string_view Expression, const std::string_view Message, const std::source_location& Location)
    {
        std::cerr << "Assertion Failed: " << Expression << '\n'
                  << "Message: " << Message << '\n'
                  << "File: " << Location.file_name() << '\n'
                  << "Line: " << Location.line() << '\n'
                  << "Function: " << Location.function_name() << '\n';

        if (!Message.empty())
        {
            std::cerr << "Message: " << Message << '\n';
        }

        TANO_DEBUG_BREAK();
        std::terminate();
    }

    template <typename Callable>
    constexpr void Debug::ExecuteIfDebug(Callable&& Callback)
    {
#ifdef TANO_DEBUG
        std::forward<Callable>(Callback)();
#endif
    }
} // namespace Tano
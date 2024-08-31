#pragma once
#include <cstddef>
#include <iostream>
#include <source_location>
#include <span>
#include <string_view>

namespace Tano
{
    class Debug
    {
    public:
        Debug() = delete;
        ~Debug() = delete;

    public:
        static void HandleAssert(const std::string_view Expression, const std::string_view Message = "", const std::source_location& Location = std::source_location::current());

        template <typename Callable>
        static constexpr void ExecuteIfDebug(Callable&& Callback);

        static void MemoryDump(std::span<const std::byte> Data, const std::source_location& Location = std::source_location::current());
    };
} // namespace Tano

#ifdef TANO_DEBUG
#define TANO_ASSERT(Expression, ...)                                 \
    do {                                                             \
        if (!(Expression))                                           \
        {                                                            \
            ::Tano::Debug::HandleAssert(#Expression, ##__VA_ARGS__); \
        }                                                            \
    } while (0)

#ifdef _MSC_VER
#define TANO_DEBUG_BREAK() __debugbreak()
#else
#include <csignal>
#define TANO_DEBUG_BREAK() std::raise(SIGTRAP)
#endif
#else
#define TANO_ASSERT(Expression, ...) ((void) 0)
#define TANO_DEBUG_BREAK() ((void) 0)
#endif
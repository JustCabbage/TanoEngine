#pragma once
#include <cstddef>
#include <iostream>
#include <span>
#include <string_view>

#if __has_include(<experimental/source_location>)
#include <experimental/source_location>
namespace std
{
    using source_location = std::experimental::source_location;
}
#else
#include <source_location>
#endif

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
        static constexpr void ExecuteIfDebug(Callable&& Callback)
        {
#ifdef TANO_DEBUG
            std::forward<Callable>(Callback)();
#endif
        }

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
#ifndef SIGTRAP
#define SIGTRAP 5
#endif
#define TANO_DEBUG_BREAK() std::raise(SIGTRAP)
#endif
#else
#define TANO_ASSERT(Expression, ...) ((void) 0)
#define TANO_DEBUG_BREAK() ((void) 0)
#endif
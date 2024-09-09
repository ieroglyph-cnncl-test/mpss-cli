#include <mpss/CloudInfoFetcher.hpp>
#include <mpss/ContentDownloader.hpp>

#include <cxxopts.hpp>
#include <exception>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <memory>

int main(int argc, char **argv)
try {
    cxxopts::Options options("mpss-cli", "Utility for fetching info on current Ubuntu releases");
    // clang-format off
    options.add_options()
    ("l,list", "Get list of currently supported Ubuntu releases, latest versions")
    ("c,current", "Get the version of current Ubuntu LTS release. If used together with -l, the current version will always be printed last.")
    ("s,sha256", "Get the sha256 of the image file for the specified release. Works only with currently supported releases. For supported releases see output of -l", cxxopts::value<std::string>())
    ("h,help", "Print usage");
    // clang-format on

    const auto params{ options.parse(argc, argv) };

    auto cd = std::make_unique<mpss::ContentDownloader>();
    auto fetcher = std::make_unique<mpss::CloudInfoFetcher>(std::move(cd));

    bool somethingDone{ false };

    if (params.count("help") > 0) {
        fmt::print(options.help());
        return 0;
    }
    if (params.count("list") > 0) {
        fmt::print("{}\n", fmt::join(fetcher->getSupportedReleases(), "\n"));
        somethingDone = true;
    }
    if (params.count("current") > 0) {
        fmt::print("{}\n", fetcher->getCurrentLtsRelease());
        somethingDone = true;
    }
    if (params.count("sha256") > 0) {
        const auto release = params["sha256"].as<std::string>();
        fmt::print("{}\n", fetcher->getSha256(release));
        somethingDone = true;
    }
    if (!somethingDone) {
        fmt::print(options.help());
    }

    return 0;
} catch (const cxxopts::exceptions::exception &e) {
    fmt::print("Error parsing command line args. Try --help for usage details.");
    return 1;
} catch (const std::runtime_error &e) {
    fmt::print("Failed with exception: {}", e.what());
    return 2;
} catch (...) {
    fmt::print("Failed with unknown exceptions");
    return 3;
}
// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "Navigine",
    platforms: [
        .iOS(SupportedPlatform.IOSVersion.v9),
    ],
    products: [
        .library(
            name: "Navigine",
            targets: ["Navigine"])
    ],
    dependencies: [
    ],
    targets: [
        .binaryTarget(
            name: "Navigine",
            path: "Navigine.xcframework"
        ),
        .testTarget(
            name: "NavigineTests",
            dependencies: ["Navigine"]
        ),
    ]
)

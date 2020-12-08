import XCTest
import Navigine

final class NavigineTests: XCTestCase {
    
    func testImport() {
        let core = NavigineCore()
        XCTAssertEqual(core.server, "https://api.navigine.com")        
    }
    
}

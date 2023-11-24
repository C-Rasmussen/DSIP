#include <iostream>
#include <vector>

template <size_t N>
class LinearBuffer {
private:
    std::vector<double> buffer;

public:
    // Constructor to initialize the buffer size
    LinearBuffer() {
        buffer.resize(N, 0.0);
    }

    // Function to add a new value to the buffer and shift the existing values
    void shift(double newValue) {
        // Shift elements to the front, discarding the oldest one
        for (size_t i = N - 1; i > 0; --i) {
            buffer[i] = buffer[i - 1];
        }
        buffer[0] = newValue; // Add the new value at the front
    }

    // Function to retrieve the value at a specific index in the buffer
    double getValueAtIndex(int index) const {
        if (index >= 0 && index < N) {
            return buffer[index];
        } else {
            std::cerr << "Index out of bounds!" << std::endl;
            return 0.0;
        }
    }

    // Function to get the current buffer contents
    std::vector<double> getBuffer() const {
        return buffer;
    }
};

// Example usage
int main() {
    const size_t bufferSize = 8; // Change the buffer size as needed
    LinearBuffer<bufferSize> buffer;

    // Simulating real-time input signal (replace this with actual input)
    std::vector<double> inputSignal = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    // Adding values to the buffer
    for (double value : inputSignal) {
        buffer.shift(value);

        // Replace this line with processing or utilization of the buffer contents
        std::vector<double> currentBuffer = buffer.getBuffer();
        std::cout << "Buffer contents: ";
        for (double val : currentBuffer) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

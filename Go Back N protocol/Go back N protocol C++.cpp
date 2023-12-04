#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int errors_every_num;
struct Frame {
    int seq_num;
    string data;

    void dummy_data() {
        data = "";
        // 8 random bits of data to be sent
        for (int i = 0; i < 8; i++)
            data = data + char('0' + rand() % 2);
    }
};
class Go_back_n {
private:
    int n; // window size;
    int num_of_frames; // number of frames to be sent;
    vector<Frame> frames_to_be_sent;
    deque<Frame> received_buffer;
    queue<Frame> received_frames;
    vector<bool> received_successfully;
    int frame_to_be_sent;
    int frame_to_be_ack;

    int from_physical_layer() {
        if ((received_buffer.empty() || frame_to_be_ack != received_buffer.front().seq_num)) {
            cout << "Frame " << frame_to_be_ack << " is not received or no acknowledgement received\n";
            return 0;  // neg acknowledgement or acknowledgement not received
        }

        if (frame_to_be_ack == received_buffer.front().seq_num) {
            cout << "Getting acknowledgement for frame " << frame_to_be_ack << " from physical layer...\n";
            return 1; // pos acknowledgement
        }
    }

    void to_physical_layer(const Frame &frame) {
        cout << "\nFrame " << frame.seq_num << " is being sent...\n";
        cout << "\n****************************************************\n\n";
        int rec_success = rand() % errors_every_num;
        if (rec_success)
            received_buffer.push_back(frame);
    }

    Frame from_network_layer() {
        cout << "Getting frame " << frame_to_be_sent << " from network layer...\n";
        cout << "Data to be sent : " << frames_to_be_sent[frame_to_be_sent - 1].data << '\n';
        Frame frame = frames_to_be_sent[frame_to_be_sent - 1];
        return frame;
    }

public:
    Go_back_n(int n, int num_of_frames) {
        this->n = n;
        this->num_of_frames = num_of_frames;
        frame_to_be_sent = 1;
        frame_to_be_ack = frame_to_be_sent - n;
        received_successfully.resize(num_of_frames+1);
        frames_to_be_sent.resize(num_of_frames);
        for (int i = 0; i < num_of_frames; i++) {
            frames_to_be_sent[i].seq_num = i + 1;
            frames_to_be_sent[i].dummy_data();
        }
    }

    void run() {
        while (frame_to_be_ack <= num_of_frames) {
            if (frame_to_be_sent > n && !received_successfully[frame_to_be_ack]) {
                int ack = from_physical_layer();
                if (ack) {
                    cout << "Frame " << frame_to_be_ack << " acknowledged successfully\n";
                    cout << "\n****************************************************\n\n";
                    received_frames.push(received_buffer.front());
                    received_buffer.pop_front();
                    received_successfully[frame_to_be_ack] = true;
                } else {
                    cout << "Retransmitting frames starting from frame " << frame_to_be_ack << '\n';
                    cout << "\n****************************************************\n\n";
                    frame_to_be_sent = frame_to_be_ack;
                    frame_to_be_ack = frame_to_be_sent - n;
                    received_buffer.clear();
                    continue;
                }
            }
            if (frame_to_be_sent <= num_of_frames) {
                Frame frame = from_network_layer();
                to_physical_layer(frame);
            }
            frame_to_be_sent++;
            frame_to_be_ack++;
        }
    }
};

int main() {
    srand(time(0));
    int window_size = 4; // window size (n)
    int num_of_frames = 10; // number of frames we want to send
    errors_every_num = 6; // larger value means less probability of error ( 1 means 100% error ( forever transmission) , 2 means 50% error , 3 means 33.33% and so on)
    Go_back_n protocol(window_size, num_of_frames);
    cout << "Protocol 5 (Go-Back-N) simulation.\n";
    cout << "window size is : " << window_size << " and number of frames to be sent is : " << num_of_frames << ".\n";
    cout << "Probability of error for every frame is : " << (1.0 / errors_every_num)*100 << "%\n";
    cout << "**************************************************************************************\n\n";

    protocol.run();
    cout << "All frames Arrived successfully\n";
    return 0;
}
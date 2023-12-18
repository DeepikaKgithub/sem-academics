 #include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_FILE "myfifo"

int main() {
    // Create a FIFO (named pipe)
    mkfifo(FIFO_FILE, S_IRUSR | S_IWUSR);

    // Writer Process
    if (fork() == 0) {
        int fd = open(FIFO_FILE, O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Write data to the FIFO
        char message[] = "Hello from the writer process!";
        write(fd, message, sizeof(message));

        // Close the file descriptor
        close(fd);

        exit(EXIT_SUCCESS);
    }

    // Reader Process
    else {
        int fd = open(FIFO_FILE, O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Read data from the FIFO
        char buffer[100];
        read(fd, buffer, sizeof(buffer));
        printf("Reader Process: Received message - %s\n", buffer);

        // Close the file descriptor
        close(fd);

        // Remove the FIFO
        unlink(FIFO_FILE);

        exit(EXIT_SUCCESS);
    }
}
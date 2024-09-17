#include <stdio.h>
#include <stdlib.h>

void compress_file(const char *input_file, const char *output_file) {
    // TODO: Implement the compression algorithm (e.g., RLE or Huffman Encoding)
    printf("Compressing %s into %s\n", input_file, output_file);

    // Open the input file for reading
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Failed to open input file");
        return;
    }

    // Open the output file for writing
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Failed to open output file");
        fclose(input);
        return;
    }

    // Example: Read file byte by byte (You will implement the actual compression logic here)
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        // Placeholder: Write the unmodified data to the output file
        fputc(ch, output);
    }

    // Close the files
    fclose(input);
    fclose(output);

    printf("Compression completed successfully.\n");
}

void decompress_file(const char *input_file, const char *output_file) {
    // TODO: Implement the decompression algorithm
    printf("Decompressing %s into %s\n", input_file, output_file);

    // Open the input file for reading
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Failed to open input file");
        return;
    }

    // Open the output file for writing
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Failed to open output file");
        fclose(input);
        return;
    }

    // Example: Read file byte by byte (You will implement the actual decompression logic here)
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        // Placeholder: Write the unmodified data to the output file
        fputc(ch, output);
    }

    // Close the files
    fclose(input);
    fclose(output);

    printf("Decompression completed successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <compress|decompress> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    const char *mode = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];

    if (strcmp(mode, "compress") == 0) {
        compress_file(input_file, output_file);
    } else if (strcmp(mode, "decompress") == 0) {
        decompress_file(input_file, output_file);
    } else {
        printf("Invalid mode. Use 'compress' or 'decompress'.\n");
        return 1;
    }

    return 0;
}

# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY fb.c .
# Compile the C program
RUN gcc -o fb fb.c
# Set the command to run when the container starts
CMD ["./fb"]
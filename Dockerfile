# Use an official, minimal base Alpine image
FROM alpine:latest

# Install GCC, Make, and Musl-dev
RUN apk add --no-cache gcc musl-dev make

# Set the working directory
WORKDIR /app

# Copy the shell source code into the container
COPY . .

# Compile the shell program
RUN make

# Start the shell by default
CMD ["./shell"]

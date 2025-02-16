make re && ./server &  
sleep 1  

# Get the correct server PID  
SERVER_PID=$(pgrep -f "./server")  

if [ -z "$SERVER_PID" ]; then  
    echo "Error: Server failed to start."  
    exit 1  
fi  

# Basic message test  
echo "Test 1: Sending 'Hello, Minitalk!'"  
./client "$SERVER_PID" "Hello, Minitalk!"  
echo
sleep 1  

# Empty message test  
echo "Test 2: Sending an empty message"  
./client "$SERVER_PID" ""  
echo
sleep 1  

# Special characters test  
echo "Test 3: Sending special characters"  
./client "$SERVER_PID" "!@#$%^&*()_+-={}[]:\";'<>?,./"  
echo
sleep 1  

# Long message test  
echo "Test 4: Sending a long message"  
long_msg=$(head -c 500 </dev/urandom | tr -dc 'a-zA-Z0-9')  
./client "$SERVER_PID" "$long_msg"  
echo
sleep 1  

# Unicode characters test  
echo "Test 5: Sending Unicode characters"  
./client "$SERVER_PID" "🚀🔥🎉💻"  
echo
sleep 1  

# Kill the server after tests  
kill "$SERVER_PID"

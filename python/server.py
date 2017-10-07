import socket
import thread

work = True

def work_with_client(client, dir):
    size = 2048
    while True:
        try:
            data = client.recv(size)
            if data:
                data = data.split(" ")
                if (data[0] == "GET" and len(data) > 2):
                    file = str(dir) + str(data[1])
                    try:
                        file_o = open(file, "r")
                        file_c = file_o.read()
                        to_send = "HTTP/1.0 200 Document follows\n"
                        to_send = str(to_send) +  "Content-Length: " + str(len(file_c)) + "\n\n"
                        to_send = str(to_send) + str(file_c)
                        client.sendall(to_send)
                    except:
                        client.sendall("HTTP/1.0 404 Not Found")
                else:
                    client.close()
                    print ("client isnt http client")
                    return False
            else:
                client.close()
                print ("client disconnected")
                return False
        except:
            client.close()
            print ("client crash")

            return False

def stop_work(server, fake):
    user_input = raw_input()
    print "stoping"
    if user_input == "stop":
        work = False
        server.close()

def main():
    dir = "/home/fihmany/PycharmProjects/httpServer/"
    #dir = raw_input("Enter the site Dir")
    server_s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_s.bind(('0.0.0.0', 82))
    server_s.listen(5)
    while work:
        try:
            (client_s, client_addr) = server_s.accept()
            #client_s.settimeout = 60
            work_with_client(client_s,dir)
        except:
            server_s.close()
    server_s.close()
    print "stopped"
    return True

if __name__ == "__main__":
    main()
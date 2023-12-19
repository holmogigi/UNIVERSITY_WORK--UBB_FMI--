package org.example;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Peers {
    // Server and client ports and the username
    private final int svrPort;
    private final int clientPort;
    private final String username;

    // Constructor to initialize the ports and username
    public Peers(int svrPort, int clientPort, String username) {
        this.clientPort = clientPort;
        this.svrPort = svrPort;
        this.username = username;
    }

    // Method to start the client
    private void StartClient() {
        try (Scanner scanner = new Scanner(System.in)) {
            // Keep reading messages from the console and send them
            while (true) {
                System.out.print(">> ");
                String message = scanner.nextLine();

                String ipAddress = "localhost";
                int peerPort = clientPort;

                SendMessage(ipAddress, peerPort, message);
            }
        }
    }

    // Method to handle a client
    private void HandleClient(Socket socket) {
        try (Scanner scanner = new Scanner(socket.getInputStream());
             PrintWriter writer = new PrintWriter(socket.getOutputStream(), true)) {

            // Keep reading messages from the client and print them
            while (true) {
                if (scanner.hasNextLine()) {
                    String receivedMessage = scanner.nextLine();
                    System.out.println(receivedMessage);
                    System.out.print(">> ");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Method to send a message to a peer
    private void SendMessage(String ipAddress, int peerPort, String message) {
        try (Socket socket = new Socket(ipAddress, peerPort);
             PrintWriter writer = new PrintWriter(socket.getOutputStream(), true)) {

            // Send the message
            writer.println(username + ": " + message);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Method to start the server
    private void StartServer() {
        try (ServerSocket serverSocket = new ServerSocket(svrPort)) {
            System.out.println("server on " + svrPort);
            System.out.print(">> ");
            // Keep accepting client connections
            while (true) {
                Socket clientSocket = serverSocket.accept();
                // Handle each client in a new thread
                new Thread(() -> HandleClient(clientSocket)).start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Method to start the application
    public void StartApp() {
        // Start the server in a new thread
        new Thread(this::StartServer).start(); //TODO THREAD POOLS
        // Start the client
        StartClient();
    }

    // Main method to start the application
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("username: ");
            String name = scanner.nextLine();

            System.out.print("client port: ");
            int clientPort = Integer.parseInt(scanner.nextLine());

            System.out.print("server port: ");
            int serverPort = Integer.parseInt(scanner.nextLine());

            // Create a Peers object and start it
            Peers peer = new Peers(serverPort, clientPort, name);
            peer.StartApp();
        } catch (Exception e) {
            e.printStackTrace();
        };
    }
}
//TODO EXCP HANDLE
# TCP Asio Project

Projekt TCP Asio to przykład aplikacji klient-serwer, wykorzystującej bibliotekę Boost.Asio do komunikacji sieciowej. Projekt można skompilować i uruchomić za pomocą CMake i Visual Studio.

## Wymagania

- [CMake](https://cmake.org/download/)
- [Boost](https://www.boost.org/users/download/)
- [Visual Studio](https://visualstudio.microsoft.com/)

## Instalacja

1. **Pobierz repozytorium:**

    ```sh
    git clone https://github.com/k-surma/tcp_cmake.git
    cd tcp_cmake
    ```

2. **Pobierz i zainstaluj Boost:**

    Pobierz Boost z [Boost Downloads](https://www.boost.org/users/download/) i rozpakuj go w wybranej lokalizacji. Skonfiguruj Boost zgodnie z instrukcjami na stronie.

3. **Skonfiguruj ścieżki Boost:**

    Utwórz plik `local_config.cmake` w głównym katalogu projektu i dodaj do niego ścieżki do Boost:

    ```cmake
    # local_config.cmake

    # Ustawienie ścieżki do Boost
    set(BOOST_ROOT "C:/Users/User/Downloads/boost_1_85_0/boost_1_85_0")
    set(BOOST_INCLUDEDIR "C:/Users/User/Downloads/boost_1_85_0/boost_1_85_0")
    set(BOOST_LIBRARYDIR "C:/Users/User/Downloads/boost_1_85_0/boost_1_85_0/stage/lib")
    set(Boost_NO_SYSTEM_PATHS TRUE)
    ```

4. **Budowanie projektu:**

    Otwórz terminal i wykonaj następujące kroki:

    ```sh
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ```

5. **Uruchomienie projektu:**

    Po skompilowaniu projektu, w katalogu `build` znajdziesz plik wykonywalny `tcp_cmake`. Możesz go uruchomić, aby wybrać tryb serwera lub klienta.

    ```sh
    ./tcp_cmake
    ```

## Użytkowanie

Po uruchomieniu aplikacji:

1. Wybierz tryb:
    - `1` dla serwera
    - `2` dla klienta

2. Postępuj zgodnie z instrukcjami wyświetlanymi na ekranie.

### Tryb serwera:

Serwer nasłuchuje na porcie `12345` i akceptuje połączenia od klientów. Wszystkie wiadomości otrzymane od jednego klienta są rozsyłane do pozostałych klientów.

### Tryb klienta:

Klient łączy się z serwerem na `127.0.0.1:12345`. Możesz wysyłać wiadomości, które będą odbierane przez inne połączone klienty oraz odbierać wiadomości od innych klientów.

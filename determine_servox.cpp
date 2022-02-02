#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#define ACCELITE_SERV_NUM 1

void servoErrorstandardCheckCommand();
void servoErrorDetailCheckCommand(int servoID, unsigned char readbuf, int re);
void allErrorJuging();
std::string to_binString(unsigned int val);

int main()
{
    std::ofstream write;
    std::string filename = "sample.txt";
    write.open(filename, std::ios::out);

    allErrorJuging();
    return 0;
}

/*サーボの標準エラーを検出し、エラー内容を書き込む*/
void servoErrorstandardCheckCommand(int servoID, unsigned char readbuf)
{
    unsigned char sendbuf;
    std::ofstream write;
    std::string filename = "sample.txt";
    write.open(filename, std::ios::app);

    std::vector<std::string> error_list = {"system_error", "motor_error", "UART_error", "command_error"};
    unsigned char sendcommand[] = {0x01, 0x02, 0x03, 0x04};
    //struct ServoStatus s;
    //std::cout << to_binString(readbuf) << "\n";
    if (readbuf != 0x99)
    {
        for (int i = 0; i < error_list.size(); i++)
        {
            std::stringstream ss;
            unsigned char check_bit = 1;
            if (readbuf & (check_bit << i))
            {
                // std::cout << "test" << std::endl;
                ss << "mode:" << i << " "
                   << "[" << servoID << "]" << error_list[i];
                sendbuf = sendcommand[i];
                sendbuf = 0x05; //送って受け取る
                //std::cout << to_binString(sendbuf) << "\n";

                if (sendbuf == 0x00)
                {
                    ss << "\n"
                       << " Not detail error" << std::endl;
                }

                std::string s = ss.str();
                std::cout << s << std::endl;
                const char *msg = s.c_str();
                if (s.size() != 0)
                {
                    //std::cout << msg;
                    write << msg << std::endl;
                    //syslog(LOG_DEBUG, "test");
                }
                servoErrorDetailCheckCommand(servoID, sendbuf, i);
            }
        }
    }
}

/*サーボの詳細エラーを検出し、エラー内容を書き込む*/
void servoErrorDetailCheckCommand(int servoID, unsigned char readbuf, int re) //reha
{
    std::ofstream write;
    std::string filename = "sample.txt";
    write.open(filename, std::ios::app);

    std::stringstream ss;
    std::vector<std::vector<std::string>> error_detail_list = {
        {"Watchdog_Timer_error", "MCU_error", "Memory_error", "input_voltage_error", "MCU_temple_up", "AD_false", "I2C_false", "SPI_false"},
        {"Motor_temperature_error", "Motor_lock", "Moter_Current", "holeIC_error"},
        {"Framing_error", "Parity_error", "Break_error", "Overrun_error"},
        {"Checksum_error", "command_device_error", "data_too_long", "adress_defalt", "command_error"}};

    if (readbuf != 0x99)
    {
        for (int i = 0; i < error_detail_list[re].size(); i++)
        {
            unsigned char check_bit = 1;

            if (readbuf & (check_bit << i))
            {
                ss << " mode:" << i << " "
                   << "[" << servoID << "]" << error_detail_list[re][i] << std::endl;
            }
        }
        std::string s = ss.str();
        const char *msg = s.c_str();
        if (s.size() != 0)
        {
            write << s << std::endl;
            //syslog(LOG_DEBUG, "test");
        }
    }
}

/*すべてのサーボエラーを検出する*/
void allErrorJuging()
{
    for (int i = 1; i < ACCELITE_SERV_NUM + 1; i++)
    {
        unsigned char readbuf;
        //struct ServoStatus s;
        readbuf = 0x7; //送って受け取る
        //std::cout << to_binString(readbuf) << "\n";
        servoErrorstandardCheckCommand(i, readbuf);
    }
}

// 数値を２進数文字列に変換
std::string to_binString(unsigned int val)
{
    if (!val)
        return std::string("0");
    std::string str;
    while (val != 0)
    {
        if ((val & 1) == 0)               // val は偶数か？
            str.insert(str.begin(), '0'); //  偶数の場合
        else
            str.insert(str.begin(), '1'); //  奇数の場合
        val >>= 1;
    }
    return str;
}

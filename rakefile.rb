require 'ceedling'
Ceedling.load_project

# Run all tests and build the release by default.
task :default => %w[ logging test:all release target:hex]

namespace:target do

    # Dummy task to ensure that the SERIAL_PORT environment variable is set.
    # It can be set on the command line as follows:
    #   $ rake SERIAL_PORT=[serial port name]
    task :serial_port do
        unless ENV['SERIAL_PORT']
            raise "SERIAL_PORT is not defined in the environment!"
        end
    end

    desc "Convert the output binary to a hex file for programming"
    task :hex => :release do
        bin_file = "#{PROJECT_BUILD_ROOT}/release/#{RELEASE_BUILD_OUTPUT}.bin"
        hex_file = "#{PROJECT_BUILD_ROOT}/release/#{RELEASE_BUILD_OUTPUT}.hex"
        cmd = "#{ENV['OBJCOPY']} -O ihex -R .eeprom #{bin_file} #{hex_file}"
        puts "Converting to hex..."
        sh cmd
    end

    desc "Program the microcontroller over the serial port"
    task :load=> [:hex, :serial_port] do
        hex_file = "#{PROJECT_BUILD_ROOT}/release/#{RELEASE_BUILD_OUTPUT}.hex"
        cmd = "avrdude -v -p #{ENV['MCU']} -c avrisp2 -P #{ENV['SERIAL_PORT']} -B 8 -U flash:w:#{hex_file}"
        puts "Loading to board..."
        sh cmd
    end

    desc "Make a backup hex image of the flash contents"
    task :backup, [:backup_name] => :serial_port do |t, args|
        cmd = "avrdude -v -p #{ENV['MCU']} -c avrisp2 -P #{ENV['SERIAL_PORT']} -B 8 -U lash:r:#{args.backup_name}:i"
        puts "Making backup..."
        sh cmd
    end
end

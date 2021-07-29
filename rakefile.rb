ENV['LINTER'] = "tools/clang-format/windows/clang-format.exe"
ENV['PVS_FREE_UTILS'] = "tools/pvs-studio/windows/How-To-Use-PVS-Studio-FREE.exe"
ENV['LOGS_ROOT'] = "build/logs/"
ENV['SRC_ROOT'] = "src/user"

PROJECT_CEEDLING_ROOT = "vendor/ceedling"
load "#{PROJECT_CEEDLING_ROOT}/lib/ceedling.rb"
Ceedling.load_project

desc "Generate documentation" 
task :doxygen do
  sh "doxygen Doxygen.conf"
end

desc "Prepare static analyzer"
task :pvstudio_prepare do  
  sh "#{ENV['PVS_FREE_UTILS']} --c 2 #{ENV['SRC_ROOT']}"
end

desc "Run static analyzer"
task :pvstudio do  
  sh "CLMonitor.exe monitor & waitfor aaa /t 5 2> NUL & ceedling clean & ceedling project:microchip release & CLMonitor.exe analyze -l \"#{ENV['LOGS_ROOT']}pvs.plog\""
end

desc "Run linter" 
task :linter do
  puts Dir.pwd
  files = Dir["#{ENV['SRC_ROOT']}/**/*.c"]
  files.each do |file_name|
    if !File.directory? file_name
      cmd = "#{ENV['LINTER']} -i --style=Microsoft #{file_name}"
      puts "#{cmd}"
    end
  end
end

# desc "Convert the output binary to a hex file"
# task :convert => :release do
#   elf_file = "build/release/#{RELEASE_BUILD_OUTPUT}"
#   cmd = "#{ENV['COMPILER_ROOT']}bin/xc32-bin2hex #{elf_file}.elf"
#   puts "Generating #{RELEASE_BUILD_OUTPUT}.hex..."
#   puts cmd
#   sh cmd
# end

# desc "Convert the output binary to a hex file for programming to the STM"
# task :convert => :release do
#   bin_file = "build/release/#{RELEASE_BUILD_OUTPUT}"
#   hex_file = "build/release/#{RELEASE_BUILD_OUTPUT}.hex"
#   cmd = "/usr/local/x-tools/gcc-arm-none-eabi/bin/arm-none-eabi-objcopy -O ihex #{bin_file} #{hex_file}"
#   puts cmd
#   sh cmd
# end

# desc "Print size of exported built elf file"
# task :size => :release do
#   bin_file = "build/release/#{RELEASE_BUILD_OUTPUT}"
#   cmd = "xc32-size --format=berkeley #{bin_file}"
#   puts cmd
#   sh cmd
# end

# desc "Get assembly listing of built elf file"
# task :list do
#   bin_file = "build/release/#{RELEASE_BUILD_OUTPUT}"
#   cmd = "/usr/local/x-tools/gcc-arm-none-eabi/bin/arm-none-eabi-objdump -D -S #{bin_file} > #{bin_file}.list"
#   puts cmd
#   sh cmd
# end

# task :release do
#     Rake::Task[:convert].invoke
#     Rake::Task[:size].invoke
# end

# desc "Program the PIC"
# task :program => :convert do
#   hex_file = "build/release/#{RELEASE_BUILD_OUTPUT}.hex"
#   cmd = "#{ENV['MPLABX_ROOT']}mplab_ipe/ipecmd.sh -P#{ENV['MCU']} -TPPK3 -M -OL -F#{hex_file}"
#   puts "Programming #{RELEASE_BUILD_OUTPUT}.hex..."
#   puts cmd
#   sh cmd
# end
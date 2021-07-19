#include <stdio.h>
#include <Windows.h>
#include <winbase.h>
#include <stdint.h>
#include <strsafe.h>
#include <iostream>
#include <winioctl.h>
#include <conio.h>
#include <math.h>
#include <time.h>

#define UNICODE 1
#define _UNICODE 1



/* Very pleased with the results from my HarvardX MOOC study, getting the ideas across of C, maybe re-enrol to refresh  			 */
/* DOD_STD_DRIVE_ERASE, open-source drive erasure software, compiled with VS2019 x64 for Windows 10					         */
/* I love you Dad, Mark William Watters														 */
/* Authored by Charles Thomas Wallace Truscott Watters for thievingmagpie.software and github.com/ctwtruscottwatters   				 */
/* Very eager to become fluent in C++ (not just C) and C++ data structures and algorithms (stacks, heaps, queues, lists, sorting, searching)     */

BOOL get_drive_geometry(LPCWSTR path, DISK_GEOMETRY * disk_geometry_structure) {
	printf("CALCULATING DRIVE GEOMETRY\n");
	HANDLE hDevice = INVALID_HANDLE_VALUE;
	BOOL bResult = FALSE;
	DWORD junk = 0;
	hDevice = CreateFileW(path, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if(hDevice == INVALID_HANDLE_VALUE) {
		printf("CANNOT ACCESS DISK\t%d\n", GetLastError());
		return FALSE;
	} else {
		printf("SUCCESSFUL IN ACCESSING DISK\n");
	}
	bResult = DeviceIoControl(hDevice, IOCTL_DISK_GET_DRIVE_GEOMETRY, NULL, 0, disk_geometry_structure, sizeof(* disk_geometry_structure), &junk, (LPOVERLAPPED) NULL);
	if(!bResult) {
		printf("ERROR: %d", GetLastError());
	}
	CloseHandle(hDevice);
	return (bResult);
}

int main(void) {
	DWORD my_drives = 200;
	char drive_strings[200];
	memset(drive_strings, 0, 200);
	DWORD GetDrives = GetLogicalDriveStringsW(my_drives, (LPWSTR) drive_strings);
	int drive_count;
	printf("WELCOME TO DOD STANDARD DRIVE ERASE. AUTHORED BY CHARLES T.W. TRUSCOTT WATTERS\n");
	printf("thievingmagpie.software\n\n");
	printf("#################### PLEASE SELECT A DRIVE ####################\n\n");
	printf("   ");
	for(drive_count = 0; drive_count <= 200; ++drive_count){
		printf("%c", drive_strings[drive_count]);
		if(drive_strings[drive_count] == 0x5C) {
			printf("\n\n");
		}
		if(drive_strings[drive_count] == 0x000 && drive_count > 80) {
			break;
		}
	}
	printf("\n");
	printf("###############################################################\n");

	printf("ENTER DRIVE LETTER (e.g. C, D, E, e.t.c.): ");
/*	scanf("%c", &drive_letter);
	char * path;
	strcpy(path, "\\\\.\\");
	strcat(path, (char *) drive_letter);
	strcat(path, ":");
	printf("%s", (char *) path);
	wchar_t drive_path[10];
	for(int p = 0; p <= 10; ++p) {
		drive_path[p] = (wchar_t) path[p];
		printf("%c", path[p]);
	}
*/
	char * path = "\\\\.\\";
	char drive_letter[100];
	if(!fgets(drive_letter, 32, stdin)) {
		printf("DONE.\n");
	}
	int i = 0;
	LPCWSTR drive_path_access;
	while(drive_letter[i] != '\n') {
		if(drive_letter[i] == 'A') {
			wchar_t drive_string[7] = L"\\\\.\\A:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'B') {
			wchar_t drive_string[7] = L"\\\\.\\B:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'C') {
			wchar_t drive_string[7] = L"\\\\.\\C:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'D') {
			wchar_t drive_string[7] = L"\\\\.\\D:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'E') {
			wchar_t drive_string[7] = L"\\\\.\\E:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'F') {
			wchar_t drive_string[7] = L"\\\\.\\F:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'G') {
			wchar_t drive_string[7] = L"\\\\.\\G:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'H') {
			wchar_t drive_string[7] = L"\\\\.\\H:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'I') {
			wchar_t drive_string[7] = L"\\\\.\\I:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'J') {
			wchar_t drive_string[7] = L"\\\\.\\J:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'K') {
			wchar_t drive_string[7] = L"\\\\.\\K:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'L') {
			wchar_t drive_string[7] = L"\\\\.\\L:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'M') {
			wchar_t drive_string[7] = L"\\\\.\\M:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'N') {
			wchar_t drive_string[7] = L"\\\\.\\N:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'O') {
			wchar_t drive_string[7] = L"\\\\.\\O:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'P') {
			wchar_t drive_string[7] = L"\\\\.\\P:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'Q') {
			wchar_t drive_string[7] = L"\\\\.\\Q:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'R') {
			wchar_t drive_string[7] = L"\\\\.\\R:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'S') {
			wchar_t drive_string[7] = L"\\\\.\\S:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'T') {
			wchar_t drive_string[7] = L"\\\\.\\T:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'U') {
			wchar_t drive_string[7] = L"\\\\.\\U:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'V') {
			wchar_t drive_string[7] = L"\\\\.\\V:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'W') {
			wchar_t drive_string[7] = L"\\\\.\\W:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'X') {
			wchar_t drive_string[7] = L"\\\\.\\X:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'Y') {
			wchar_t drive_string[7] = L"\\\\.\\Y:";
			drive_path_access = drive_string;
		}
		if(drive_letter[i] == 'Z') {
			wchar_t drive_string[7] = L"\\\\.\\Z:";
			drive_path_access = drive_string;
		}


		++i;
	}
	DISK_GEOMETRY dg = { 0 };
	get_drive_geometry(drive_path_access, &dg);
	wprintf(L"SECTOR SIZE: %ld\n", dg.BytesPerSector);
	ULONGLONG selected_drive_size = dg.Cylinders.QuadPart * (ULONG) dg.TracksPerCylinder * (ULONG) dg.SectorsPerTrack * (ULONG) dg.BytesPerSector;
	wprintf(L"DRIVE IS %I64d BYTES ",  selected_drive_size);
	wprintf(L"OR %.2f GB\n", (double) selected_drive_size / (1024 * 1024 * 1024));
	Sleep(5000);
	HANDLE AccessDisk = CreateFileW(drive_path_access, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (AccessDisk == INVALID_HANDLE_VALUE) {
		printf("CANNOT ACCESS DISK, BYE!\n");
		exit(1);
	}

	int limiting_value = 0;
	LARGE_INTEGER position = { 0 };
	BOOL get_file_pointer = SetFilePointerEx(AccessDisk, position, NULL, FILE_BEGIN);
	BYTE zero_buffer[512];
	int zero_count;
	for(zero_count = 0; zero_count <= 512; ++zero_count) {
		BYTE zero_byte = 0;
		zero_buffer[zero_count] = zero_byte;
	}
	DWORD status;
	if(!DeviceIoControl(AccessDisk, FSCTL_DISMOUNT_VOLUME, NULL, 0, NULL, 0, &status, NULL)){
		printf("DISMOUNT FAILED, BYE!\n%d", GetLastError());
		exit(1);
	}
	ULONGLONG sector_count = 0;
	LARGE_INTEGER position_again;
	while((ULONGLONG) (sector_count * 512) <= (ULONGLONG) selected_drive_size){
		LARGE_INTEGER position_again;
		position_again.QuadPart = sector_count * 512; 
		get_file_pointer = SetFilePointerEx(AccessDisk, position_again, NULL, FILE_BEGIN);
		
		BOOL write_to_disk = WriteFile(AccessDisk, zero_buffer, 512, NULL, NULL);
		printf("Writing to sector %I64u \t %I64u bytes left\t %I64u bytes written", (ULONGLONG) (position_again.QuadPart), (ULONGLONG) (selected_drive_size) - (ULONGLONG) (position_again.QuadPart), (ULONGLONG) (sector_count * 512));
		printf("\n");
		printf("#################### %.6lf %c DONE (PASS 1, ZEROES) ####################\n", (long double) (100.0 * (((double) (sector_count * 512)) / (double) (selected_drive_size))), 0x25);
		if (!write_to_disk) {
			printf("WRITING TO SECTOR %I64u FAILED, DRIVE CONTAMINATED\n", (ULONGLONG) position_again.QuadPart);
			printf("%d\n", GetLastError());
		}
		sector_count += 1;
	}
	printf("#################### 100 %c DONE (PASS 1, ZEROES) ####################\n", 0x25);
	printf("%I64u BYTES SUCCESSFULLY ERASED, PASS 1 COMPLETED\n", (ULONGLONG) (sector_count * 512));
	BYTE one_buffer[512];
	int one_count;
	for(one_count = 0; one_count <= 512; ++one_count) {
		BYTE one_byte = 1;
		one_buffer[one_count] = one_byte;
	}
	ULONGLONG sector_count_pass_two = 0;
	LARGE_INTEGER position_again_pass_two;
	while((ULONGLONG) (sector_count_pass_two * 512) <= (ULONGLONG) selected_drive_size){
		LARGE_INTEGER position_again_pass_two;
		position_again_pass_two.QuadPart = sector_count_pass_two * 512;
		get_file_pointer = SetFilePointerEx(AccessDisk, position_again_pass_two, NULL, FILE_BEGIN);
		BOOL write_to_disk = WriteFile(AccessDisk, one_buffer, 512, NULL, NULL);
		printf("Writing to sector %I64u \t %I64u bytes left\t %I64u bytes written", (ULONGLONG) (position_again_pass_two.QuadPart), (ULONGLONG) (selected_drive_size) - (ULONGLONG) (position_again_pass_two.QuadPart), (ULONGLONG) (sector_count_pass_two * 512));
		printf("\n");
		printf("#################### %.6lf %c DONE (PASS 2, ONES) ####################\n", (long double) (100.0 * (((double) (sector_count_pass_two * 512)) / (double) (selected_drive_size))), 0x25);
		if (!write_to_disk) {
			printf("WRITING TO SECTOR %I64u FAILED, DRIVE CONTAMINATED\n", (ULONGLONG) position_again_pass_two.QuadPart);
			printf("%d\n", GetLastError());
		}
		sector_count_pass_two += 1;
	}
	printf("#################### 100 %c DONE (PASS 2, ONES) ####################\n", 0x25);
	printf("%I64u BYTES SUCCESSFULLY ERASED, PASS 2 COMPLETED\n", (ULONGLONG) (sector_count_pass_two * 512));


	ULONGLONG sector_count_pass_three = 0;
	LARGE_INTEGER position_again_pass_three;
	while((ULONGLONG) (sector_count_pass_three * 512) <= (ULONGLONG) selected_drive_size){
		BYTE rand_buffer[512];
		int rand_count;
		time_t t;
		srand((unsigned) time(&t));
		for(rand_count = 0; rand_count <= 512; ++rand_count) {
			BYTE rand_byte = rand() % 255;
			rand_buffer[rand_count] = rand_byte;
		}
		position_again_pass_three.QuadPart = sector_count_pass_three * 512;
		get_file_pointer = SetFilePointerEx(AccessDisk, position_again_pass_three, NULL, FILE_BEGIN);
		BOOL write_to_disk = WriteFile(AccessDisk, rand_buffer, 512, NULL, NULL);
		printf("Writing to sector %I64u \t %I64u bytes left\t %I64u bytes written", (ULONGLONG) (position_again_pass_three.QuadPart), (ULONGLONG) (selected_drive_size) - (ULONGLONG) (position_again_pass_three.QuadPart), (ULONGLONG) (sector_count_pass_three * 512));
		printf("\n");
		printf("#################### %.6lf %c DONE (PASS 3, PRNG'd NUMBERS) ####################\n", (long double) (100.0 * (((double) (sector_count_pass_three * 512)) / (double) (selected_drive_size))), 0x25);
		if (!write_to_disk) {
			printf("WRITING TO SECTOR %I64u FAILED, DRIVE CONTAMINATED\n", (ULONGLONG) position_again_pass_three.QuadPart);
			printf("%d\n", GetLastError());
		}
		sector_count_pass_three += 1;
	}
	printf("#################### 100 %c DONE (PASS 3, PRNG'd NUMBERS) ####################\n", 0x25);
	printf("%I64u BYTES SUCCESSFULLY ERASED, PASS 3 COMPLETED\n", (ULONGLONG) (sector_count_pass_three * 512));
	printf("##############################################################################\n");
	printf("##############################################################################\n");
	printf("##############################################################################\n");
	printf("########	DRIVE ERASED WITH 3 PASSES OF ZEROES, ONES	      ########\n");
	printf("########	AND PSUEDO-RANDOM GENERATED NUMBERS. FINISHED	      ########\n");
	printf("##############################################################################\n");
	printf("##############################################################################\n");
	printf("##############################################################################\n");
	printf("#########	CHARLES T.W. TRUSCOTT WATTERS		              ########\n");
	printf("#########	THIEVINGMAGPIE.SOFTWARE 		              ########\n");
	printf("##############################################################################\n");
	printf("##############################################################################\n");
	printf("##############################################################################\n");
	

	CloseHandle(AccessDisk);
	return 0;
}
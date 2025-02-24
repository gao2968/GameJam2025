#pragma once

#include <map>
#include <string>
#include <vector>

/// <summary>
/// ���\�[�X�Ǘ��N���X
/// </summary>
class ResourceManager
{
private:
	// ���N���X�̃|�C���^�i���̂�A�h���X�̐�ŕۗL�j
	static ResourceManager* instance;

	std::map<std::string, std::vector<int>> images_container;	// �摜�R���e�i
	std::map<std::string, int> sounds_container;				// �����R���e�i

private:
	// �N���X�̎��̂�����o�֐���ł��������ł��Ȃ��悤�ɂ���
	ResourceManager() = default;

	// �R�s�[�K�[�h
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator = (const ResourceManager&) = delete;
	// ~�R�s�[�K�[�h

public:
	~ResourceManager() = default;

	/// <summary>
	/// �C���X�^���X�擾����
	/// </summary>
	/// <returns>�C���X�^���X�̃|�C���^��ԋp����</returns>
	static ResourceManager* GetInstance();

	/// <summary>
	/// �C���X�^���X�폜����
	/// </summary>
	static void DeleteInstance();

public:
	/// <summary>
	/// �摜�擾����
	/// </summary>
	/// <param name="file_name">�t�@�C���p�X</param>
	/// <param name="all_num">�摜�̕�������</param>
	/// <param name="num_x">���̕���</param>
	/// <param name="num_y">�c�̕���</param>
	/// <param name="size_x">���̃T�C�Y(px)</param>
	/// <param name="size_y">�c�̃T�C�Y(px)</param>
	/// <returns>�ǂݍ��񂾉摜�n���h����vector�z��</returns>
	const std::vector<int>& GetImages(std::string file_name, int all_num = 1, int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);
	/// <summary>
	/// �摜�擾����
	/// </summary>
	/// <param name="file_name">�t�@�C���p�X</param>
	/// <param name="all_num">�摜�̕�������</param>
	/// <param name="num_x">���̕���</param>
	/// <param name="num_y">�c�̕���</param>
	/// <param name="size_x">���̃T�C�Y(px)</param>
	/// <param name="size_y">�c�̃T�C�Y(px)</param>
	/// <returns>�ǂݍ��񂾉摜�n���h����vector�z��</returns>
	const std::vector<int>& GetImages(const char* file_name, int all_num = 1, int num_x = 1, int num_y = 1, int size_x = 0, int size_y = 0);

	/// <summary>
	/// �����擾����
	/// </summary>
	/// <param name="file_path">�����̃t�@�C���p�X</param>
	/// <returns>�����n���h���f�[�^</returns>
	int GetSounds(std::string file_path);
	/// <summary>
	/// �����擾����
	/// </summary>
	/// <param name="file_path">�����̃t�@�C���p�X</param>
	/// <returns>�����n���h���f�[�^</returns>
	int GetSounds(const char* file_path);

	/// <summary>
	/// �摜�������
	/// </summary>
	void UnLoadImages();

	/// <summary>
	/// �����������
	/// </summary>
	void UnLoadSounds();

private:
	/// <summary>
	/// �摜�ǂݍ��ݏ���
	/// </summary>
	/// <param name="file_path">�t�@�C���p�X</param>
	void CreateImagesResource(std::string file_path);

	/// <summary>
	/// �摜�����ǂݍ��ݏ���
	/// </summary>
	/// <param name="file_name">�t�@�C���p�X</param>
	/// <param name="all_num">�摜�̕�������</param>
	/// <param name="num_x">���̕���</param>
	/// <param name="num_y">�c�̕���</param>
	/// <param name="size_x">���̃T�C�Y(px)</param>
	/// <param name="size_y">�c�̃T�C�Y(px)</param>
	void CreateImagesResource(std::string file_name, int all_num, int num_x, int num_y, int size_x, int size_y);

	// �����ǂݍ��ݏ���
	void CreateSoundsResource(std::string file_path);
};


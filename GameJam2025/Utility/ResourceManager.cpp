#include "ResourceManager.h"
#include "DxLib.h"

// �ÓI�����o�ϐ���`
ResourceManager* ResourceManager::instance = nullptr;	// ���N���X�̃|�C���^

/// <summary>
/// �C���X�^���X�擾����
/// </summary>
/// <returns>�C���X�^���X�̃|�C���^��ԋp����</returns>
ResourceManager* ResourceManager::GetInstance()
{
	// �C���X�^���X����������Ă��Ȃ��ꍇ�A��������
	if (instance == nullptr)
	{
		instance = new ResourceManager();
	}

	return instance;
}

/// <summary>
/// �C���X�^���X�폜����
/// </summary>
void ResourceManager::DeleteInstance()
{
	// �C���X�^���X����������Ă���ꍇ�A�폜����
	if (instance != nullptr)
	{
		// �摜���\�[�X�̉��
		instance->UnLoadImages();
		// �������\�[�X�̉��
		instance->UnLoadSounds();
		// �C���X�^���X��폜����
		delete instance;
		instance = nullptr;
	}
}

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
const std::vector<int>& ResourceManager::GetImages(std::string file_name, int all_num, int num_x, int num_y, int size_x, int size_y)
{
	// �R���e�i��ɉ摜�f�[�^�������ꍇ�A�摜�ǂݍ��݂�s��
	if (images_container.count(file_name) == NULL)
	{
		// �����ǂݍ��݂�s���H�s��Ȃ��H
		if (all_num == 1)
		{
			// �����ǂݍ��݂�s��Ȃ�
			CreateImagesResource(file_name);
		}
		else
		{
			// �����ǂݍ��݂�s��
			CreateImagesResource(file_name, all_num, num_x, num_y, size_x, size_y);
		}
	}

	// �R���e�i��̃f�[�^��Ԃ�
	return images_container[file_name];
}
const std::vector<int>& ResourceManager::GetImages(const char* file_name, int all_num, int num_x, int num_y, int size_x, int size_y)
{
	return GetImages(std::string(file_name), all_num, num_x, num_y, size_x, size_y);
}

/// <summary>
/// �����擾����
/// </summary>
/// <param name="file_path">�����̃t�@�C���p�X</param>
/// <returns>�����n���h���f�[�^</returns>
int ResourceManager::GetSounds(std::string file_path)
{
	// �R���e�i��Ɏw��t�@�C����������΁A��������
	if (sounds_container.count(file_path) == NULL)
	{
		// �����̓ǂݍ��݂�s��
		CreateSoundsResource(file_path);
	}

	// �R���e�i��̃f�[�^��Ԃ�
	return sounds_container[file_path];
}
int ResourceManager::GetSounds(const char* file_path)
{
	return GetSounds(std::string(file_path));
}

/// <summary>
/// �摜�������
/// </summary>
void ResourceManager::UnLoadImages()
{
	// �R���e�i��ɉ摜��������΁A������I������
	if (images_container.size() == NULL)
	{
		return;
	}

	// �S�Ẳ摜��폜
	for (std::pair<std::string, std::vector<int>> value : images_container)
	{
		DeleteSharingGraph(value.second[0]);
		value.second.clear();
	}

	// �R���e�i����
	images_container.clear();
}

/// <summary>
/// �����������
/// </summary>
void ResourceManager::UnLoadSounds()
{
	// �R���e�i��ɉ�����������΁A������I������
	if (sounds_container.size() == NULL)
	{
		return;
	}

	// �S�Ẳ摜��폜
	for (std::pair<std::string, int> value : sounds_container)
	{
		DeleteSoundMem(value.second);
	}

	// �R���e�i����
	sounds_container.clear();
}

/// <summary>
/// �摜�ǂݍ��ݏ���
/// </summary>
/// <param name="file_path">�t�@�C���p�X</param>
void ResourceManager::CreateImagesResource(std::string file_path)
{
	// �w�肳�ꂽ�摜�t�@�C���ǂݍ���
	int handle = LoadGraph(file_path.c_str());

	// �G���[�`�F�b�N
	if (handle == -1)
	{
		throw (file_path + "������܂���\n");
	}

	// �R���e�i�ɓǂݍ��񂾉摜��ǉ�����
	images_container[file_path].push_back(handle);
}
void ResourceManager::CreateImagesResource(std::string file_name, int all_num, int num_x, int num_y, int size_x, int size_y)
{
	// ��������摜��������������m�ۂ���
	int* handle = new int[all_num];

	// �w�肳�ꂽ�摜�t�@�C���𕪊��œǂݍ���
	int result = LoadDivGraph(file_name.c_str(), all_num, num_x, num_y, size_x, size_y, handle);

	// �G���[�`�F�b�N
	if (result == -1)
	{
		throw (file_name + "������܂���\n");
	}

	// �R���e�i�ɓǂݍ��񂾉摜��ǉ�����
	for (int i = 0; i < all_num; i++)
	{
		images_container[file_name].push_back(handle[i]);
	}

	// �m�ۂ�����������������
	delete[] handle;
}

void ResourceManager::CreateSoundsResource(std::string file_path)
{
	// �w�肳�ꂽ�t�@�C����ǂݍ���
	int handle = LoadSoundMem(file_path.c_str());

	// �G���[�`�F�b�N
	if (handle == -1)
	{
		throw (file_path + "������܂���\n");
	}

	// �R���e�i�ɓǂݍ��񂾉�����ǉ�����
	sounds_container[file_path] = handle;
}
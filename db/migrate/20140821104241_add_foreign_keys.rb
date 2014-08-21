class AddForeignKeys < ActiveRecord::Migration
  def change
    add_column :users, :api_key_id, :integer
    add_column :api_keys, :user_id, :integer
  end
end

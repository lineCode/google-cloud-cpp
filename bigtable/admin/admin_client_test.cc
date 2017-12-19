// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "bigtable/admin/admin_client.h"

#include <gmock/gmock.h>

TEST(AdminClientTest, Simple) {
  // TODO() - this is not much of a test because the behavior is not observable.
  // We should change the AdminClient to have a dependency injection point to
  // at least verify it is doing something.
  auto admin_client =
      bigtable::CreateAdminClient("test-project", bigtable::ClientOptions());
  EXPECT_TRUE(admin_client);
  EXPECT_EQ("test-project", admin_client->project());
  EXPECT_NO_THROW(admin_client->table_admin());
  EXPECT_NO_THROW(admin_client->on_completion(grpc::Status::CANCELLED));
  EXPECT_NO_THROW(admin_client->table_admin());
}